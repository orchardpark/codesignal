bool solution(string passcode, vector<string> attempts) {
    int consecutive = 0;
    for(auto attempt : attempts){
        if(passcode != attempt) consecutive++;
        else consecutive = 0;
        if(consecutive>=10) return true;
    }
    return false;

}

