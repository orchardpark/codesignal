double solution(vector<vector<int>> trainingData) {
    double sum = 0;
    int count = 0;
    for(auto it: trainingData){
        auto result = it.at(1);
        if(result==1){
            sum += it.at(0);
            count ++;
        }
    }
    if(count==0) return sum;
    return sum/count;
}

