class Job
{
    public:
    Job(int start_time, int time_to_comlete, int index, int request_time) : start_time(start_time), time_to_comlete(time_to_comlete), index(index), request_time(request_time) {visited=false;}
    int start_time;
    int request_time;
    int time_to_comlete;
    bool visited;
    int index;
    int sort_time() const{
        return start_time+time_to_comlete;
    }
    bool operator <(const Job& rhs) const
    {
        return this->sort_time() < rhs.sort_time();
    }
};

vector<int> solution(vector<int> requestTime, vector<int> jobProcess, int timeFromStart) {
    int N = requestTime.size();
    vector<bool> visited(N, false);
    int t=0;
    vector<Job>q;
    for(int i=0; i<N; i++){
        q.push_back(Job(requestTime[i], jobProcess[i], i, requestTime[i]));
    }
    
    while(t<=timeFromStart)
    {
        bool picked = false;
        sort(q.begin(), q.end());
        for(int i=0; i<N; i++)
        {
            if(!q[i].visited && q[i].start_time<=t){
                if(q[i].start_time<=timeFromStart){
                    t=q[i].sort_time();
                    for(int j=0; j<N; j++){
                        q[j].start_time = max(t, q[j].start_time);
                    }
                    q[i].visited=true;
                    picked=true;
                    break;
                }
            }
        }
        if(!picked)t+=1;
    }
    vector<int> result;
    sort(q.begin(), q.end(), [] (const Job& lhs, const Job& rhs){return lhs.time_to_comlete<rhs.time_to_comlete;});
    for(int i=0; i<N; i++)
    {
        if(!q[i].visited && q[i].request_time<=timeFromStart){
            result.push_back(q[i].index);
        }
    }
    return result;
    
}
