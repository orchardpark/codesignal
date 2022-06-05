vector<int> solution(int maxPrice, vector<int> vendorsDelivery, vector<vector<int>> vendorsProducts) {
    vector<int> vendors;
    int num_products = vendorsProducts[0].size();
    int num_vendors = vendorsDelivery.size();
    vector<int> sorted_delivery_times;
    copy(vendorsDelivery.begin(), vendorsDelivery.end(), back_inserter(sorted_delivery_times));
    sort(sorted_delivery_times.begin(), sorted_delivery_times.end());
    for(auto& delivery_time_limit : sorted_delivery_times)
    {
        // check if possible for this delivery time
        vendors.clear();
        int tot_cost=0;
        bool possible=true;
        for(int i=0; i<num_products; i++)
        {
            int best_cost = INT_MAX;
            int vendor = -1;
            for(int j=0; j<num_vendors; j++){
                if(vendorsDelivery[j]<=delivery_time_limit && vendorsProducts[j][i] != -1){
                    int cost = vendorsProducts[j][i];
                    if(cost < best_cost)
                    {
                        best_cost = cost;
                        vendor = j;
                    }
                }
            }
            tot_cost += best_cost;
            if(vendor==-1 || tot_cost > maxPrice) {
                possible = false;
                break;
            }
            if(find(vendors.begin(), vendors.end(), vendor)==vendors.end()) vendors.push_back(vendor);
        }
        
        if(possible) break;
    }
    
    
    return vendors;

}
