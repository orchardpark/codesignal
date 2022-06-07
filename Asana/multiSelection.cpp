vector<string> solution(vector<int> dimensions, vector<string> tasks, vector<vector<int>> mouseCoordinates) {
    vector<string> res;
    
    // horizontal line
    if(mouseCoordinates[0][1]==mouseCoordinates[1][1]){
        int height = mouseCoordinates[0][1];
        int lowWidth = min(mouseCoordinates[0][0], mouseCoordinates[1][0]);
        int highWidth = max(mouseCoordinates[0][0], mouseCoordinates[1][0]);
        for(int i=0; i<tasks.size(); i++)
        {
            int topY = i*dimensions[1]+i*dimensions[2];
            int bottomY = (i+1)*dimensions[1]+i*dimensions[2];
            if(height >= topY && height <= bottomY 
            && lowWidth <= dimensions[0] && highWidth>=0
            && find(res.begin(), res.end(), tasks[i])==res.end()
            )
                res.push_back(tasks[i]);
        }
        return res;
    }
    
    // vertical line
    if(mouseCoordinates[0][0]==mouseCoordinates[1][0]){
        int width = mouseCoordinates[0][0];
        int lowHeight = min(mouseCoordinates[0][1], mouseCoordinates[1][1]);
        int highHeight = max(mouseCoordinates[0][1], mouseCoordinates[1][1]);
        for(int i=0; i<tasks.size(); i++)
        {
            int topY = i*dimensions[1]+i*dimensions[2];
            int bottomY = (i+1)*dimensions[1]+i*dimensions[2];
            if(highHeight >= topY &&  lowHeight <= bottomY 
            && width <= dimensions[0] && width>=0
            && find(res.begin(), res.end(), tasks[i])==res.end()
            )
                res.push_back(tasks[i]);
        }
        return res;
    }
    
    // other
    vector<int> low;
    vector<int> high;
    if(mouseCoordinates[0][1]<mouseCoordinates[1][1])
    {
        low = mouseCoordinates[0];
        high = mouseCoordinates[1];
    }
    else{
        low = mouseCoordinates[1];
        high = mouseCoordinates[0];
    }
    
    int minHeight = low[1];
    int maxHeight = high[1];
    int minWidth = low[0];
    
    double slope = (double)(high[0]-low[0]) / (double)(high[1]-low[1]);
    
    for(int height=minHeight; height<=maxHeight; height++)
    {
        double width = minWidth+slope*(height-minHeight);
        if(width>=0 && width < dimensions[0]){
            for(int i=0; i<tasks.size(); i++)
            {
                int topY = i*dimensions[1]+i*dimensions[2];
                int bottomY = (i+1)*dimensions[1]+i*dimensions[2];
                if(height >= topY && height <= bottomY && find(res.begin(), res.end(), tasks[i])==res.end())
                    res.push_back(tasks[i]);
            }
            
        }
    }
    
    
    return res;
}
