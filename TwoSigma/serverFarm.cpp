bool sort_function(pair<int, int> i, pair<int,int> j){
    if (j.first == i.first){
        return i.second < j.second;
    }
    return j.first < i.first;
}
vector<vector<int>> solution(vector<int> jobs, int servers) {
    vector<vector<int>> res(servers, vector<int>());
    vector<int> times(servers, 0);
    vector<pair<int, int>> jobsNamed;
    for(int i=0; i<jobs.size(); i++){
        jobsNamed.push_back(pair<int, int>(jobs[i], i));
    }
    sort(jobsNamed.begin(),jobsNamed.end(), sort_function);
    for(auto it : jobsNamed){
        int min = min_element(times.begin(), times.end())-times.begin();
        times[min] += it.first;
        res.at(min).push_back(it.second);
    }
    return res;
    
}

