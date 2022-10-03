// Finds the augmenting path
bool bfs(int start, int end, vector<vector<int>>& network, vector<int>& parent){
    vector<bool> visited(network.size(), false);
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int front = q.front(); q.pop();
        if(front==end) return true;
        visited[front]=true;
        for(int i=0; i<network.size(); i++)
        {
            if(network[front][i]>0 && !visited[i]){
                q.push(i);
                parent[i]=front;
            }
        }
    }
    return false;
}

int max_flow(int start, int end, vector<vector<int>>& network)
{
    int maxF = 0;
    vector<int> parent(network.size());
    while(bfs(start, end, network, parent)){
        int node = end;
        int path_flow = 1000000;
        
        while(node != start){
            int edge = network[parent[node]][node];
            path_flow = min(path_flow, edge);
            node = parent[node];
        }
        node = end;
        while(node != start)
        {
            network[parent[node]][node] -= path_flow;
            network[node][parent[node]] += path_flow;
            node = parent[node];
        }
        maxF += path_flow;
    }
    return maxF;
}
int solution(int resource, int server, vector<vector<int>> network) {
    return max_flow(resource, server, network);
}
