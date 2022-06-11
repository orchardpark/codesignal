int median(vector<int>& v, bool round_down)
{
    if(v.size()&1) return v[v.size()/2];
    else{
        double first = v[v.size()/2-1];
        double second = v[v.size()/2];
        if(round_down) return (int)floor((first+second)/2);
        else return (int)ceil((first+second)/2);
    }
}

vector<int> solution(vector<int> contractData) {
    vector<int> res;
    if(contractData.size()<2) return res;
    sort(contractData.begin(), contractData.end());
    int n = contractData.size();
    int mid = n/2;
    vector<int> first; vector<int> second;
    for(int i=0; i<mid; i++) first.push_back(contractData[i]);
    for(int i=mid; i<n; i++) second.push_back(contractData[i]);
    res.push_back(median(first, true));
    res.push_back(median(second, false));
    return res;
}
