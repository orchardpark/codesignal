class Worker{
    public:
    Worker(string name, int numProjects, int numTasks, bool onVacation) : name(name), numProjects(numProjects), numTasks(numTasks), onVacation(onVacation) {}
    string name;
    int numProjects;
    int numTasks;
    bool onVacation;
    
    bool operator<(const Worker& __rhs) const {
        if(this->onVacation == __rhs.onVacation){
            if(this->numTasks == __rhs.numTasks){
                return this->numProjects < __rhs.numProjects;
            }
            else{
                return this->numTasks < __rhs.numTasks;
            }
        }
        else{
            return this->onVacation < __rhs.onVacation;
        }
        
    }
};

string solution(vector<string> names, vector<bool> statuses, vector<int> projects, vector<int> tasks) {
    int n = names.size();
    vector<Worker> workers;
    for(int i=0; i<n; i++)
    {
        workers.emplace_back(Worker(names[i], projects[i], tasks[i], statuses[i]));
    }
    sort(workers.begin(), workers.end());
    return workers.begin()->name;
}
