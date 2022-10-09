int solution(int marathonLength, int maxScore, int submissions, int successfulSubmissionTime) {
    if(successfulSubmissionTime ==-1) return 0;
    int submissionPenalty = max(0, submissions-1)*10;
    double timePenalty = (maxScore / 2.0) * (1.0/marathonLength) * successfulSubmissionTime;
    int score = maxScore - submissionPenalty - timePenalty;
    
    return max(score, maxScore/2);   

}
