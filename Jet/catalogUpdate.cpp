vector<vector<string>> solution(vector<vector<string>> catalog, vector<vector<string>> updates) {
    vector<vector<string>> result;
    map<string, set<string>> catalogMap;
    for(auto it : catalog)
    {
        string category = it[0];
        catalogMap[category] = set<string>();
        for(int i=1; i<it.size(); i++)
        {
            catalogMap[category].insert(it[i]);
        }
    }
    for(auto update : updates)
    {
        string category = update[0];
        string item = update[1];
        if(catalogMap.find(category)==catalogMap.end()) catalogMap[category] = set<string>();
        catalogMap[category].insert(item);
    }
    for(auto it : catalogMap)
    {
        vector<string> categoryList;
        categoryList.push_back(it.first);
        categoryList.insert(categoryList.end(), it.second.begin(), it.second.end());
        result.push_back(categoryList);
    }
    return result;

}
