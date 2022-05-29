enum Direction { up, right, down, left };

class Position {
public:
  Position(int x, int y) : x(x), y(y) {}
  int x;
  int y;
  void move_in_direction(Direction direction) {
    switch (direction) {
    case Direction::up:
      y -= 1;
      break;
    case Direction::right:
      x += 1;
      break;
    case Direction::down:
      y += 1;
      break;
    case Direction::left:
      x -= 1;
      break;
    }
  }
  vector<int> to_vector() { return vector<int>{x, y}; }
  string to_string(){
      stringstream ss;
      ss << x << " " << y;
      return ss.str();
  }
};

Direction get_orientation(int dx, int dy){
    if(dx>0 && dy>0) return Direction::right;
    else if(dx<0 && dy>0) return Direction::down;
    else if(dx<0 && dy<0) return Direction::left;
    else return Direction::up;
}

bool isNextTaken(Position& position, Direction& direction, vector<vector<int>>& grid)
{
    switch (direction) {
        case Direction::up:
            if(position.y==0) return false;
            return grid[position.x][position.y-1];
        case Direction::right:
            return grid[position.x+1][position.y];
        case Direction::down:
            return grid[position.x][position.y+1];
        case Direction::left:
            if(position.x==0) return false;
            return grid[position.x-1][position.y];
    }
}

bool is_cornerpoint(Position& position, vector<vector<int>>& grid, vector<int>& firstPoint, vector<int>& secondPoint, Direction& direction)
{
    
    return (position.x==firstPoint[0] && position.y==firstPoint[1]) || 
    (position.x == firstPoint[0] && position.y == secondPoint[1]) ||
    (position.x == secondPoint[0] && position.y == firstPoint[1]) ||
    (position.x == secondPoint[0] && position.y == secondPoint[1]) ||
    isNextTaken(position, direction, grid);
    
}

Direction new_direction(Direction direction){
    switch (direction) {
        case Direction::up:
            return Direction::right;
        case Direction::right:
            return Direction::down;
        case Direction::down:
            return Direction::left;
        case Direction::left:
            return Direction::up;
    }
}

vector<vector<int>> solution(vector<int> firstPoint, vector<int> secondPoint) {
    int dx = secondPoint[0] - firstPoint[0];
    int dy = secondPoint[1] - firstPoint[1];
    if(dx==0 || dy==0) return vector<vector<int>>{firstPoint, secondPoint};
    vector<vector<int>> grid(101,vector<int>(101,0));
    vector<vector<int>> res;
    auto position = Position(firstPoint[0], firstPoint[1]);
    auto direction = get_orientation(dx, dy);
    bool has_started = false;
    while(!grid[position.x][position.y]){
        cout << position.to_string() << endl;
        if(is_cornerpoint(position, grid, firstPoint, secondPoint, direction)){
            res.push_back(position.to_vector());
            if(has_started){
                direction = new_direction(direction);
            }
        }
        has_started = true;
        grid[position.x][position.y]=1;
        position.move_in_direction(direction);
    }
    
    return res;
}
