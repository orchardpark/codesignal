class Solver{
    public:
    
    Solver(int origWorkingHours, int minDay, vector<int> tasks) : origWorkingHours(origWorkingHours), tasks(tasks), minDay(minDay) {
        counter=0;
    }
    
    int origWorkingHours;
    int minDay;
    vector<int> tasks;
    int counter;
    
    void dfs(int& i, int workingHours, vector<int>& visited, int day, int& numVisited)
    {
    counter++;
    if(counter>18000000) return;
    visited[i]=1;
    numVisited++;
    if(workingHours<tasks[i])
    {
        day++;
        workingHours = origWorkingHours;
    }
    if(day>=minDay) return;
    workingHours -= tasks[i];
    if(numVisited==tasks.size()){
        if(workingHours!=origWorkingHours)day++;
        minDay = min(minDay, day);
    }
    else{
        for(int i=0; i<tasks.size(); i++)
        {
            if(!visited[i])
            {
                dfs(i, workingHours, visited, day, numVisited);
                visited[i]=0;
                numVisited--;
            }
        }
    }

    }
    
};

int solution(int workingHours, vector<int> tasks) {
    int n = tasks.size();
    if(*(max_element(tasks.begin(), tasks.end())) > workingHours) return -1;
    vector<int> visited;
    int minDay = INT_MAX;
    visited = vector<int>(tasks.size(), 0);
    int day = 0;
    int numVisited = 0;
    
    // take 1 items
    for(int i=0; i<n; i++){
        if(tasks[i]==workingHours){
            visited[i]=1;
            day++;
            numVisited++;
        }
    }
    
    // take 2 items
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
        if(!visited[i] && !visited[j] && tasks[j]+tasks[i]==workingHours){
            visited[i]=1;
            visited[j]=1;
            day++;
            numVisited+=2;
        }
        }
    }
    
    Solver s(workingHours,minDay, tasks);
    int pos=-1;
    for(int i=0; i<n; i++) if(!visited[i]){pos=i;break;}
    if(pos!=-1)
    {
        s.dfs(pos, workingHours, visited, day, numVisited);
        minDay = s.minDay;
    }
    else
        minDay = day;
    return minDay;

}
