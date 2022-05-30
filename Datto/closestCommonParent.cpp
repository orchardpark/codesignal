string solution(vector<string> files, vector<string> parents, string file1, string file2) {
    int n = files.size();
    map<string, string> graph;
    for(int i=0;i<n; i++){
        graph[files[i]] = parents[i];
    }
    
    map<string, int> file1Parents;
    map<string, int> file2Parents;
    queue<pair<string, int>> parentQ;
    
    // bfs from file 1
    parentQ.push(make_pair(file1, 0));
    while(!parentQ.empty())
    {
        auto front = parentQ.front();
        file1Parents[front.first] = front.second;
        parentQ.pop();
        if(graph[front.first]!="-1") parentQ.push(make_pair(graph[front.first], front.second+1));
    }
    
    // bfs from file 2
    parentQ.push(make_pair(file2, 0));
    while(!parentQ.empty())
    {
        auto front = parentQ.front();
        file2Parents[front.first] = front.second;
        parentQ.pop();
        if(graph[front.first]!="-1") parentQ.push(make_pair(graph[front.first], front.second+1));
    }
    
    // find common parent with minimal cost
    int minDist = INT_MAX;
    string minParent = "-1";
    for(auto it=file1Parents.begin(); it!=file1Parents.end(); ++it)
    {
        auto it2 = file2Parents.find(it->first);
        if(it2!=file2Parents.end()){
            int dist = it->second+it2->second;
            if(dist < minDist){
                minDist = dist;
                minParent = it->first;
            }
        }
    }
    
    
    return minParent;
