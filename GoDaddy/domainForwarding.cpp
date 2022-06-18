string redirect(string pos, map<string,string>& graph)
{
    if(graph.find(pos)==graph.end()) return pos;
    return redirect(graph[pos], graph);
}

vector<vector<string>> solution(vector<vector<string>> redirects) {
    set<string> domains;
    map<string, string> graph;
    for(auto& it : redirects)
    {
        auto first = it.at(0);
        auto second = it.at(1);
        graph[first] = second;
        domains.insert(first);
        domains.insert(second);
    }
    map<string, vector<string>> terminals;
    for(auto& domain : domains)
    {
        auto terminal = redirect(domain, graph);
        if(terminals.find(terminal)==terminals.end()) terminals[terminal] = vector<string>();
        terminals[terminal].push_back(domain);
    }
    vector<vector<string>> res;
    for(auto it = terminals.begin(); it!=terminals.end(); it++){
        vector<string> group;
        for(auto e : it->second) group.push_back(e);
        sort(group.begin(), group.end());
        res.push_back(group);
    }
    
    return res;
}
