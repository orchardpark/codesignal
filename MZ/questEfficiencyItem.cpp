void backtrack(int pos, int timeLeftOver, int pointsGained, vector<int>& h, vector<int>& points, int& maxPoints)
{
    if(pos==h.size()){
        maxPoints = max(pointsGained, maxPoints);
    } else if(timeLeftOver<h[pos]){
        backtrack(pos+1, timeLeftOver, pointsGained, h, points, maxPoints);
    } else{
        backtrack(pos+1, timeLeftOver-h[pos], pointsGained+points[pos],h, points, maxPoints);
        backtrack(pos+1, timeLeftOver, pointsGained, h, points, maxPoints);
    }
}

int solution(vector<int> h, vector<int> points, int timeForQuests) {
    int maxPoints = 0;
    backtrack(0, timeForQuests, 0, h, points, maxPoints);
    return maxPoints;
}
