int counterAttacker(int monsterDamage, vector<int>& healthPoints)
{
    for(int i=1; i<healthPoints.size(); i++) if(healthPoints[i]>monsterDamage) return i;
    return -1;
}

int bestAttacker(vector<int>& attackDamage, vector<int>& healthPoints)
{
    int maxAttack = INT_MIN;
    int bestAttacker = -1;
    for(int i=1; i<attackDamage.size(); i++) if(healthPoints[i]>0 && attackDamage[i]>maxAttack){
        maxAttack = attackDamage[i];
        bestAttacker = i;
    }
    return bestAttacker;
}

int solution(vector<int> healthPoints, vector<int> attackDamage) {
    if(healthPoints.size()<=1) return 0;
    
    // deplete all that can withstand counter attack
    while(healthPoints[0]>0 && counterAttacker(attackDamage[0], healthPoints) != -1)
    {
        int warrior = counterAttacker(attackDamage[0], healthPoints);
        int times = (healthPoints[warrior]-1) / attackDamage[0];
        healthPoints[0] -= times*attackDamage[warrior];
        healthPoints[warrior] -= times*attackDamage[0];
    }
    
    // attack using highest damage first
    while(healthPoints[0]>0 && bestAttacker(attackDamage, healthPoints) != -1){
        int warrior = bestAttacker(attackDamage, healthPoints);
        healthPoints[0] -= attackDamage[warrior];
        if(healthPoints[0]>0)
            healthPoints[warrior] -= attackDamage[0];
        
    }
    
    int count = 0;
    for(int i=1; i<healthPoints.size(); i++) if(healthPoints[i]>0) count++;
    return count;

}
