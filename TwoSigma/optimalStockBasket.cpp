void dfs(int pos, int risk, int ret, vector<vector<int>>& stocks, int& riskBudget, int& maxReturn)
{
    if(pos>=stocks.size())
    {
        if (ret>maxReturn) maxReturn = ret;
        return;
    }
    auto stock= stocks[pos];
    if(stock[1]+risk <= riskBudget)
    {
        dfs(pos+1, risk+stock[1], ret+stock[0], stocks, riskBudget, maxReturn);
    }
    dfs(pos+1, risk, ret, stocks, riskBudget, maxReturn);
}

int solution(vector<vector<int>> stocks, int riskBudget) {
    int maxReturn = 0;
    dfs(0, 0, 0, stocks, riskBudget, maxReturn);
    return maxReturn;
}
