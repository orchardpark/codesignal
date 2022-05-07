int solution(vector<int> pkg, vector<vector<int>> boxes) {
    int bestIndex = -1;
    int bestVolume = 500*500*501;
    int i=0;
    for(auto box : boxes)
    {
        bool possible = false;
        for(int i=0; i<=2; i++){
            for(int j=0; j<=2; j++){
                for(int k=0; k<=2; k++){
                    if(i==k || i==j || j==k || possible) continue;
                    possible = pkg[0]<=box[i] && pkg[1]<=box[j] && pkg[2] <= box[k];
                }
            }
        }
        if(possible)
        {
            int volume = box[0]*box[1]*box[2];
            if(volume<bestVolume)
            {
                bestVolume = volume;
                bestIndex = i;
            }
        }
        i++;
    }
    return bestIndex;


