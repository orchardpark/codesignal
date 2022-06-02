string solution(int l, vector<double> fares) {
    vector<string> options{"UberX", "UberXL", "UberPlus", "UberBlack", "UberSUV"};
    for(int i=fares.size()-1; i>=0; i--){
        if(l*fares[i]<=20) return options[i];
    }
    return "Walking";
}
