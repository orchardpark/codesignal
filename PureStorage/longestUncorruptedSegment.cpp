vector<int> solution(vector<int> sourceArray, vector<int> destinationArray) {
    int longest_uncorrupted = 0;
    int current_uncorrupted = 0;
    int longest_startindex = 0;
    int current_startindex = 0;
    for(int i=0; i<sourceArray.size(); i++){
        if(sourceArray[i]==destinationArray[i]){
            current_uncorrupted++;
        }
        else{
            if(longest_uncorrupted < current_uncorrupted){
                longest_uncorrupted = current_uncorrupted;
                longest_startindex = current_startindex;
            }
            current_startindex = i+1;
            current_uncorrupted = 0;
        }
    }
    if(longest_uncorrupted < current_uncorrupted){
                longest_uncorrupted = current_uncorrupted;
                longest_startindex = current_startindex;
            }
    vector<int> result {longest_uncorrupted, longest_startindex};
    return result;
}

