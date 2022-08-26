vector<int> toSubset(int sol)
{
    vector<int> res;
    for(int i=0; i<=30; i++)
    {
        if(sol&(1<<i)) res.push_back(i-1);
    }
    
    return res;
}

bool isLexographicallySmaller(int first, int second)
{
    bool res=false;
    for(int i=0; i<=30; i++){
        if((first&(1<<i)) && (!(second&(1<<i)))){
            res = true;
            break;
        }
        if(!(first&(1<<i)) && ((second&(1<<i)))){
            res = false;
            break;
        }
    }
    return res;
}

vector<int> solution(vector<int> caloricValue) {
    int n = caloricValue.size();
    int m = 10000;
    // dp[i][k] == is a sum of k possible with the subset of caloricValue from [0,i]
    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
    // sdp[i][k] is the subset that leads to the sum (if possible otherwise 0)
    vector<vector<int>> sdp(n+1, vector<int>(m+1, 0));
    
    // base case
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    
    // recursive case
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(dp[i-1][j]) {
                dp[i][j]=true;
                if(sdp[i][j]==0 || isLexographicallySmaller(sdp[i-1][j], sdp[i][j]))
                    sdp[i][j] = sdp[i-1][j];
                
                dp[i][j+caloricValue[i-1]]=true;
                if(sdp[i][j+caloricValue[i-1]]==0 || isLexographicallySmaller(sdp[i-1][j]+(1<<(i)), sdp[i][j+caloricValue[i-1]]))
                    sdp[i][j+caloricValue[i-1]] = sdp[i-1][j]+(1<<(i));
            };
        }
    }
    
    // look for solution
    for(int diff=0; diff<2000; diff++)
    {
        if(dp[n][2000-diff] && dp[n][2000+diff])
        {
            if(isLexographicallySmaller(sdp[n][2000-diff], sdp[n][2000+diff]))
            {
                return toSubset(sdp[n][2000-diff]);
            }
            else {
                return toSubset(sdp[n][2000+diff]);
            }
        }
        else if(dp[n][2000-diff]){
            return toSubset(sdp[n][2000-diff]);
        }
        else if(dp[n][2000+diff]){
            return toSubset(sdp[n][2000+diff]);
        }
    }
    return vector<int>();
    
}
