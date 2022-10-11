class State
{
public:
State(int cost, int node) : cost(cost), node(node){}
int cost;
int node;
bool operator <(const State& rhs) const
{
    return this->cost > rhs.cost;   
}
};

int solution(vector<vector<int>> city) {
    priority_queue<State> q;
    q.push(State(0,0));
    vector<bool> visited(city.size(),false);
    while(!q.empty())
    {
        auto front = q.top(); q.pop();
        if(visited.at(front.node)) continue;
        else if(front.node == city.size()-1)
        {
            return front.cost;
        }
        visited[front.node]=true;
        for(int i=0; i<city.size(); i++){
            if(city[front.node][i]!=-1)
            {
                q.push(State(front.cost+city[front.node][i],i));
            }
        }
    }
    return -1;
}
