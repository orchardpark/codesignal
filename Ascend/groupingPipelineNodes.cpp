bool hasCycle(int node, map<int, set<int>>& graph, vector<bool>& visited, set<int>& reCurse)
{
    if(reCurse.find(node)!=reCurse.end()) return true;
    reCurse.insert(node);
    if(!visited[node])
    {
        visited[node]=true;
        for(auto neighbor : graph[node]){
            if(hasCycle(neighbor, graph, visited, reCurse)) return true;
        }
    }
    reCurse.erase(node);
    return false;
}

bool solution(int n, vector<vector<int>> g, vector<int> v) {
    set<int> mergedNodes(v.begin(), v.end());
    int lowest = *(mergedNodes.begin());
    map<int, set<int>> newGraph;
    vector<int> inDegree(n+1, 0);
    for(auto edge : g)
    {
        int from = mergedNodes.find(edge[0])==mergedNodes.end() ? edge[0] : lowest;
        int to = mergedNodes.find(edge[1])==mergedNodes.end() ? edge[1] : lowest;
        if(from != to)
        {
            if(newGraph.find(from)==newGraph.end()) newGraph[from] = set<int>();
            newGraph[from].insert(to);
            inDegree[to]++;
        }
    }
    bool hasEntryPoint = accumulate(inDegree.begin(), inDegree.end(),0)==0;
    vector<bool> visited;
    set<int> reCurse;
    for(auto it : newGraph)
    {
        if(inDegree[it.first]==0){
            hasEntryPoint = true;
            visited = vector<bool>(n+1, false);
            reCurse = set<int>();
            if(hasCycle(it.first, newGraph, visited, reCurse)) return false;
        }
    }
    
    return hasEntryPoint;
    
}
