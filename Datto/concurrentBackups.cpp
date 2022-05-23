void dfs(int i, int t, vector<int>& documents, vector<int>& sums, int& lowest){
    if(i==documents.size()){
        auto it = max_element(sums.begin(), sums.end());
        lowest = min(lowest, *it);
    }
    else{
        for(int j=0; j<t; j++){
            sums[j]+=documents[i];
            dfs(i+1, t, documents, sums, lowest);
            sums[j]-=documents[i];
        }
    }
}

int solution(int threads, vector<int> documents) {
    int lowest = INT_MAX;
    vector<int> sums(threads, 0);
    dfs(0, threads, documents, sums, lowest);
    return lowest;

}
