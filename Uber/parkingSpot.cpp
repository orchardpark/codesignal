bool checkLeft(vector<int>& luckySpot, vector<vector<int>>& parkingLot)
{
    for(int i=luckySpot[0]; i<=luckySpot[2]; i++)
    {
        for(int j=0; j<luckySpot[1]; j++){
            if(parkingLot[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkRight(vector<int>& luckySpot, vector<vector<int>>& parkingLot)
{
    for(int i=luckySpot[0]; i<=luckySpot[2]; i++)
    {
        for(int j=luckySpot[3]; j<parkingLot[0].size(); j++){
            if(parkingLot[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkUp(vector<int>& luckySpot, vector<vector<int>>& parkingLot)
{
    for(int i=0; i<luckySpot[0]; i++)
    {
        for(int j=luckySpot[1]; j<=luckySpot[3]; j++){
            if(parkingLot[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkDown(vector<int>& luckySpot, vector<vector<int>>& parkingLot)
{
    for(int i=luckySpot[2]; i<parkingLot.size(); i++)
    {
        for(int j=luckySpot[1]; j<=luckySpot[3]; j++){
            if(parkingLot[i][j])
            {
                return false;
            }
        }
    }
    return true;
}


bool solution(vector<int> carDimensions, vector<vector<int>> parkingLot, vector<int> luckySpot) {
    for(int i=luckySpot[0]; i<=luckySpot[2]; i++)
    {
        for(int j=luckySpot[1];j<=luckySpot[3]; j++)
        {
            if(parkingLot[i][j]) return false;
        }
    }
    
    if(carDimensions[0]==carDimensions[1])
    {
        // four sides entry
        if(checkLeft(luckySpot, parkingLot)) return true;
        if(checkRight(luckySpot, parkingLot)) return true;
        if(checkUp(luckySpot, parkingLot)) return true;
        if(checkDown(luckySpot, parkingLot)) return true;
        return false;
    }
    else{
        // entry along smallest
        int dx = luckySpot[2]-luckySpot[0];
        int dy = luckySpot[3]-luckySpot[1];
        if(dx < dy)
        {
            // left or right
            if(checkLeft(luckySpot, parkingLot)) return true;
            if(checkRight(luckySpot, parkingLot)) return true;
            return false;
        }
        else 
        {
            // up or down
            if(checkUp(luckySpot, parkingLot)) return true;
            if(checkDown(luckySpot, parkingLot)) return true;
            return false;
        }
    }
    return true;

}
