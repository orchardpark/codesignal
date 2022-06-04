double solution(vector<double> a, vector<double> b, double v1, double v2) {
    double bestSolution = 99999;
    for(float mid_point = -25.0; mid_point<=35.5; mid_point+=0.00001)
    {
        double a_dist = (a[0]*a[0])+(a[1]-mid_point)*(a[1]-mid_point);
        double b_dist = (b[0]*b[0])+(b[1]-mid_point)*(b[1]-mid_point);
        double solution = sqrt(a_dist)/v1 + sqrt(b_dist)/v2;
        bestSolution = min(bestSolution, solution);
    }
    return bestSolution;

}
