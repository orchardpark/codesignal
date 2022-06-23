double solution(vector<double> departure, vector<double> destination) {
    if(departure[0]!=destination[0] && departure[1]!=destination[1])
    {
        if(departure[1]==floor(departure[1]) && destination[1] == floor(destination[1])){
            int leftcorner = floor(departure[0]);
            int rightcorner = ceil(departure[0]);
            double cornerdistleft = departure[0]-leftcorner+abs(destination[0]-leftcorner);
            double cornerdistright = rightcorner-departure[0]+abs(destination[0]-rightcorner);
            return abs(departure[1]-destination[1]) + min(cornerdistleft, cornerdistright);
        } else if(departure[0]==floor(departure[0]) && destination[0] == floor(destination[0]))
        {
            int leftcorner = floor(departure[1]);
            int rightcorner = ceil(departure[1]);
            double cornerdistleft = departure[1]-leftcorner+abs(destination[1]-leftcorner);
            double cornerdistright = rightcorner-departure[1]+abs(destination[1]-rightcorner);
            return abs(departure[0]-destination[0]) + min(cornerdistleft, cornerdistright);
        }
        else{
            return abs(departure[0]-destination[0])+abs(departure[1]-destination[1]);
        }
    }
    else if(departure[0]!=destination[0]){
        return abs(departure[0]-destination[0]);
    }
    else if(departure[1]!=destination[1])
    {
        return abs(departure[1]-destination[1]);
    }
    else{
        return 0;
    }

}
