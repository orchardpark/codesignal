class Edge{
    public:
    Edge(int destination, int cost) : destination(destination), cost(cost) {}
    int destination;
    int cost;
};

class State {
    public:
    State(int node, int cost) : node(node), cost(cost) {}
    int node;
    int cost;
    bool operator < (const State& rhs) const {
        return rhs.cost < this->cost;
    }
};

int solution(int n, vector<vector<int>> network) {
    map<int, vector<Edge>> graph;
    for(auto link : network)
    {
        if(graph.find(link[0])==graph.end()){
            graph[link[0]] = vector<Edge>();
        }
        if(graph.find(link[1])==graph.end()){
            graph[link[1]] = vector<Edge>();
        }
        graph[link[0]].push_back(Edge(link[1], link[2]));
        graph[link[1]].push_back(Edge(link[0], link[2]));
    }
    priority_queue<State> q;
    vector<bool> visited(n+1,false);
    q.push(State(1, 0));
    while(!q.empty())
    {
        State front = q.top(); q.pop();
        if(front.node == n) return front.cost;
        if(visited[front.node]) continue;
        visited[front.node] = true;
        for(auto neighbor : graph[front.node])
        {
            q.push(State(neighbor.destination, front.cost+neighbor.cost));
        }
    }
    return -1;
    
}
