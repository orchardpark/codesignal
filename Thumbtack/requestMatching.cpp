class Pro{
  public:
  
  Pro(string name, int distance, int travelPreference) : name(name)
  {
      if(distance<=travelPreference) {
        matchingScore = distance;   
        nonMatchingScore = 0;
      }
      else{
          nonMatchingScore = distance - travelPreference;
      }
  }
  
  bool operator < (const Pro& other) const
  {
      if(this->nonMatchingScore>0 && other.nonMatchingScore>0){
          if(this->nonMatchingScore==other.nonMatchingScore) return this->name < other.name;
          return this->nonMatchingScore < other.nonMatchingScore;
      }
      else if(this->nonMatchingScore>0 && other.nonMatchingScore==0) return false;
      else if(this->nonMatchingScore==0 && other.nonMatchingScore>0) return true;
      else{
          if(this->matchingScore == other.matchingScore) return this->name < other.name;
          return this->matchingScore < other.matchingScore;
      }
  }
  
  string name;
  int matchingScore;
  int nonMatchingScore;  
};

vector<string> solution(vector<string> pros, vector<int> distances, vector<int> travelPreferences) {
    vector<string> res;
    vector<Pro> proList;
    for(int i=0; i<pros.size(); i++){
        proList.emplace_back(Pro(pros[i], distances[i], travelPreferences[i]));
    }
    sort(proList.begin(), proList.end());
    for(int i=0; i<min(5, (int)pros.size()); i++){
        res.push_back(proList[i].name);
    }
    
    return res;
}
