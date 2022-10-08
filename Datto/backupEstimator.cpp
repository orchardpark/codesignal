
class Job
{
  public:
  Job(int index, int duration) : index(index), duration(duration){}
  int index;
  double duration;
  bool operator < (const Job& rhs) const{
      return this->duration > rhs.duration;
  }
};

vector<double> solution(vector<int> startTimes, vector<int> backupDuration, int maxThreads) {
    if(startTimes.size()==0) return vector<double>();
    vector<double> completionTimes(startTimes.size());
    int i=0;
    vector<Job> queue;
    double currentTime = startTimes[0];
    int numCompleted = 0;
    while(numCompleted < startTimes.size())
    {
        // add to queue
        while(i<startTimes.size() && startTimes[i] <= currentTime && queue.size() < maxThreads)
        {
            queue.push_back(Job(i, backupDuration[i]));
            i++;
        }
        // find first completed item
        sort(queue.begin(), queue.end());
        double nextTimeDiff = ceil(currentTime)-currentTime;
        if(nextTimeDiff==0) nextTimeDiff = 1;
        double timeDiff = min(nextTimeDiff, queue.back().duration*queue.size());
        double computeDiff = min(nextTimeDiff/queue.size(), queue.back().duration);
        
        currentTime += timeDiff;
        
        // decrease duration
        for(auto& item : queue)
        {
            item.duration -= computeDiff;
        }
        
        // remove items from queue
        while(queue.back().duration<=0) {
            completionTimes[queue.back().index] = currentTime;
            queue.pop_back();
            numCompleted++;
        }   
    }
    return completionTimes;

}
