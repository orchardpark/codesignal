double solution(int s, vector<int> debts, vector<int> interests) {
    double total_spent = 0;
    int n = debts.size();
    bool payedOffDebts = accumulate(debts.begin(), debts.end(), 0)==0;
    vector<double> remainingDebts(debts.begin(), debts.end());
    
    
    while(!payedOffDebts){
        double m = s/10.0;
        while(m > 0 && !payedOffDebts){
            // find highest debt
            int highestDebtIndex = -1;
            int highestInterest = -1;
            payedOffDebts=true;
            for(int i=0;i<n; i++){
                if(remainingDebts[i]>0){
                    payedOffDebts = false;
                    if(highestInterest < interests[i]){
                        highestInterest = interests[i];
                        highestDebtIndex = i;
                    }
                }
            } 
            if(!payedOffDebts)
            {
                // pay off highest debt first
                double toPay = min(m, remainingDebts[highestDebtIndex]);
                remainingDebts[highestDebtIndex] -= toPay;
                m -= toPay;
                total_spent += toPay;
            }
        
        }
        // increase debts
        for(int i=0; i<n; i++){
            if(remainingDebts[i]>0){
                remainingDebts[i] = remainingDebts[i] + remainingDebts[i] * (interests[i] / 100.0);
            } 
        } 
        
        
    }
    
    
    
    

    return total_spent;

