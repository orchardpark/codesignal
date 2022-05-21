class SalesLead{
    public:
    string name;
    double score;
    int t;
    
    SalesLead(string name, double score, int t) : name(name), score(score), t(t) {}
    
    bool operator < (const SalesLead& other) const{
        if(this->score == other.score){
            if(this->t == other.t) return this->name < other.name;
            return this->t > other.t;
        }
        return this->score>other.score;
    }
};


vector<string> solution(vector<string> names, vector<int> t, vector<int> netValue, vector<bool> isOnVacation) {
    vector<SalesLead> leads;
    for(int i=0; i<names.size(); i++){
        if(!isOnVacation[i])
        {
            double score = (double)netValue[i]*(double)t[i]/365.0;
            string name = names[i];
            leads.emplace_back(SalesLead(name, score, t[i]));
        }
    }
    sort(leads.begin(), leads.end());
    auto f = [] (SalesLead lead) {return lead.name;};
    vector<string> sorted_names;
    transform(leads.begin(), leads.end(), back_inserter(sorted_names), f);
    return sorted_names;
}
