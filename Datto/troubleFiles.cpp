vector<int> solution(vector<vector<int>> files, vector<int> backups) {
    vector<int> trouble(backups.size(), 0);
    int i=0; // files index
    int j=0; // backup index
    int loadTime = 0;
    bool isRunningBackup = false;
    while (true)
    {
        if(isRunningBackup)
        {
            // add trouble files
            while(i<files.size() && files[i][0]<=backups[j]+loadTime)
            {
                trouble[j]++;
                i++;
            }
            
            // move to next backup
            isRunningBackup = false;
            loadTime = 0;
            j++;
            if(j>=backups.size()) break;
            
        } else {
            // add all files to queue
            while(i<files.size() && files[i][0]<=backups[j])
            {
                loadTime += files[i][1];
                i++;
            }
            // start backup
            if(loadTime > 0){
                isRunningBackup = true;
            } 
            // skip backup
            else{
                j++;
                if(j>=backups.size()) break;
            }
        }
    }
    
    return trouble;
}
