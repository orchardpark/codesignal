vector<vector<int>> solution(int blockCount, vector<vector<int>> writes, int threshold) {
    vector<int> blocks(blockCount, 0);
    for(auto const& value : writes){
        int start=value[0];
        int end=value[1];
        for(int i=start; i<=end; i++){
            blocks[i]++;
        }
    }
    vector<vector<int>> segments;
    int currentStart = -1;
    bool hasStarted = false;
    for(int i=0; i<blockCount; i++){
        if(blocks[i]>=threshold){
            if(hasStarted){
                ;
            }
            else{
                hasStarted = true;
                currentStart = i;
            }
            
        }
        else{
            if(hasStarted){
                vector<int> segment{currentStart, i-1};
                segments.push_back(segment);
            }
            hasStarted = false;
        }
    }
    if(hasStarted){
        vector<int> segment{currentStart, blockCount-1};
        segments.push_back(segment);
    }
    
    return segments;
    
}

