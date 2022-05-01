vector<int> solution(double threshold, vector<vector<int>> ratings) {
    vector<int> review;
    int i=0;
    for(auto pro : ratings){
        double avgScore = (double)accumulate(pro.begin(), pro.end(),0) / pro.size();
        if(avgScore<threshold){
            review.push_back(i);
        }
        i++;
    }
    return review;

}
