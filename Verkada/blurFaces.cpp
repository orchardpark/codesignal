vector<vector<double>> solution(vector<vector<int>> img) {
    vector<vector<double>> blurred(img.size(), vector<double>(img[0].size(), 0));
    for(int i=0; i<img.size(); i++){
        for(int j=0; j<img[0].size(); j++){
            double val = 0;
            double count = 0;
            for(int k=-1; k<=1; k++){
                for(int l=-1; l<=1; l++){
                    // same cell
                    if(k==0 && l==0) continue;
                    // out of bounds
                    else if(i+k<0 || j+l<0 || i+k>=img.size() || j+l>=img[0].size()) continue;
                    else{
                        count++;
                        val+=img[i+k][j+l];
                    }
                    
                }
            }
            blurred[i][j]=val/count;
        }
    }
    return blurred;
}
