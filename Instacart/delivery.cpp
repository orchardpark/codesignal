vector<bool> solution(vector<int> order, vector<vector<int>> shoppers) {
    vector<bool> res;
    for(auto shopper : shoppers){
        double arrivaltime = ((double)order[0]+shopper[0])/shopper[1]+shopper[2];
        if (arrivaltime >= order[1] && arrivaltime<=order[1]+order[2]) res.push_back(true);
        else res.push_back(false);
    }

    return res;
}

