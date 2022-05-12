vector<double> solution(int ride_time, int ride_distance, vector<double> cost_per_minute, vector<double> cost_per_mile) {
    int n = cost_per_minute.size();
    vector<double> estimation;
    for(int i=0; i<n; i++)
    {
        estimation.emplace_back(ride_time*cost_per_minute[i]+ride_distance*cost_per_mile[i]);
    }
    return estimation;
}

