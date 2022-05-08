int solution(int t, int allianceSize) {
    int num_boosts = min(allianceSize, 10);
    int decrease_time = max(num_boosts*60, num_boosts*int(t*0.1));
    return max(t-decrease_time, 0);
}

