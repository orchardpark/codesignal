struct Position {
    Position(int x, int y, int cost) : x(x), y(y), cost(cost){}
    int x;
    int y;
    int cost;    
};

int bfs(vector<int>& start, vector<int>& end, vector<vector<int>>& impassableCells)
{
    vector<vector<bool>> visited(42,vector<bool>(42,false));
    vector<pair<int, int>> impassable;
    transform(impassableCells.begin(), impassableCells.end(), back_inserter(impassable), [](vector<int>& v){return make_pair(v[0], v[1]);});
    queue<Position> q;
    q.push(Position(start[0], start[1], 0));
    while(!q.empty())
    {
        auto front = q.front(); q.pop();
        if(front.x == end[0] && front.y == end[1]){
            return front.cost;
        }
        if(front.x<-20 || front.y <-20 || front.x>20 || front.y> 20 || visited[front.x+20][front.y+20]) continue;
        visited[front.x+20][front.y+20] = true;
        vector<vector<int>> directions = {{0,-1}, {1,-1},{1,0},{0,1},{-1,1},{-1,0}};
        for(auto& direction : directions)
        {
            pair<int, int> newPos = make_pair(direction[0]+front.x, direction[1]+front.y);
            if(find(impassable.begin(), impassable.end(), newPos)==impassable.end())
            {
                q.push(Position(newPos.first, newPos.second, 1+front.cost));
            }
        }
    }
    return INT_MAX;
}

bool solution(vector<int> friendlyTroops, vector<int> enemyTroops, vector<int> loggingCamp, vector<vector<int>> impassableCells) {
    int friendlyDist = bfs(friendlyTroops, loggingCamp, impassableCells)*friendlyTroops[2];
    int enemyDist = bfs(enemyTroops, loggingCamp, impassableCells)*enemyTroops[2];
    return friendlyDist < enemyDist;
}
