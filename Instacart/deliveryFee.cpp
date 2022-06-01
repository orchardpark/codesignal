bool solution(vector<int> intervals, vector<int> fees, vector<vector<int>> deliveries) {
    int n = intervals.size();
    if(n==1) return true;
    vector<int> deliveriesPerInterval(n, 0);
    // assign deliveries to intervals
    for(auto& delivery : deliveries)
    {
        for(int i=1; i<n; i++){
            if(delivery[0]<intervals[i]){
                deliveriesPerInterval[i-1]++;
                break;
            }
        }
        if(delivery[0]>=intervals[n-1]) deliveriesPerInterval[n-1]++;
    }
    // check if every fee/deliveries is constant
    for(int i=0; i<n-1; i++)
    {
        auto first = (double)fees[i] / deliveriesPerInterval[i]; 
        auto second = (double)fees[i+1] / deliveriesPerInterval[i+1];
        if(first!=second) return false; 
    }
    return true;

}
