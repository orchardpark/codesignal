bool solution(vector<string> systemNames, vector<int> stepNumbers) {
    int n = systemNames.size();
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string systemName = systemNames[i];
        int stepNum = stepNumbers[i];
        if(mp.find(systemName)==mp.end()){
            mp[systemName]=stepNum;
        }
        else if(mp[systemName]>=stepNum) return false;
        else mp[systemName]=max(mp[systemName], stepNum);
    }
    return true;

}

