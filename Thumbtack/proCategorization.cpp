vector<vector<vector<string>>> solution(vector<string> pros, vector<vector<string>> preferences) {
    // map from category to pro
    map<string, vector<string>> proPerCat;
    for(int i=0; i<pros.size(); i++){
        for(auto preference : preferences[i]){
            if(proPerCat.find(preference)==proPerCat.end()) proPerCat[preference]=vector<string>();
            proPerCat[preference].push_back(pros[i]);
        }
    }
    vector<vector<vector<string>>> res;
    for(auto it : proPerCat){
        vector<vector<string>> line;
        vector<string> category;
        category.push_back(it.first);
        line.push_back(category);
        line.push_back(it.second);
        res.push_back(line);
    }
    return res;


