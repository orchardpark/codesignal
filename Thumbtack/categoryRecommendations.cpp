class Category{
    public:
    Category(string name, double score): name(name), score(score) {}
    string name;
    double score;
    bool operator < (const Category& other) const {
        if(this->score == other.score) return this->name < other.name;
        else return this->score > other.score;
    }
    
    
};

double mean(vector<double> scores)
{
    double sum = 0;
    for(auto it=scores.begin(); it!=scores.end(); ++it) sum+=*(it);
    return sum / scores.size();
}

string solution(vector<vector<string>> requestData, vector<string> proSelections) {
    int n = requestData.size();
    int m = proSelections.size();
    map<string, vector<double>> jaccard;
    for(int i=0; i<n; i++)
    {
        int numSummands = requestData[i].size();
        double numMatches = 0;
        for(int k=0; k<numSummands; k++){
            for(int j=0; j<m; j++){
                if(requestData[i][k]==proSelections[j]){
                    numMatches++;
                    break;
                }
            }
        }
        for(int k=0; k<numSummands; k++){
            if(find(proSelections.begin(), proSelections.end(),requestData[i][k])!=proSelections.end()) continue;
            if(jaccard.find(requestData[i][k])==jaccard.end()) jaccard[requestData[i][k]] = vector<double>();
            jaccard[requestData[i][k]].push_back(numMatches/numSummands);
        }
    }
    if(jaccard.empty()) return "";
    vector<Category> scores;
    for(auto& it : jaccard)
    {
        scores.emplace_back(Category(it.first, mean(it.second)));
    }
    sort(scores.begin(), scores.end());
    
    auto candidate = *(scores.begin());
    if(candidate.score<=0) return "";
    else return candidate.name;
}
