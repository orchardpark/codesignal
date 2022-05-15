vector<int> solution(vector<int> deadlines, int day) {
    vector<int> res(3,0);
    for(auto deadline : deadlines)
    {
        if(deadline<=day) res[0]++;
        else if(deadline >= day+1 && deadline <= day+7) res[1]++;
        else res[2]++;
    }
    
    
    return res;

}
