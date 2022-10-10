void backtrack(int i, vector<bool> completion, vector<bool> selectedMerchants, vector<string>& items, vector<vector<string>>& merchants, vector<int>& solution, int& numMerchants)
{
    int completionCount = accumulate(completion.begin(), completion.end(),0);
    if(i==merchants.size() && completionCount!=items.size()) return;
    else if(completionCount==items.size())
    {
        int merchantCount = accumulate(selectedMerchants.begin(), selectedMerchants.end(), 0);
        vector<int> newSolution;
        for(int j=0; j<selectedMerchants.size(); j++)
        {
            if(selectedMerchants[j]) newSolution.push_back(j);
        }
        if(solution[0]==-1||merchantCount<numMerchants)
        {
            solution = newSolution;
            numMerchants=merchantCount;
        }
        
        return;
    }
    else{
        // use merchant
        vector<bool> newCompletion = completion;
        vector<bool> newSelectedMerchants = selectedMerchants;
        newSelectedMerchants[i]=true;
        auto merchantItems = merchants[i];
        for(int j=0; j<items.size(); j++){
            if(find(merchantItems.begin(), merchantItems.end(), items[j])!=merchantItems.end())
            {
                newCompletion[j]=true;
            }
        }
        backtrack(i+1, newCompletion, newSelectedMerchants, items, merchants, solution, numMerchants);
        // don't use merchant
        backtrack(i+1,completion, selectedMerchants, items, merchants, solution, numMerchants);
    }
}


vector<int> solution(vector<string> items, vector<vector<string>> merchants) {
    vector<int> solution = {-1};
    int numMerchants = 0;
    backtrack(0, vector<bool>(items.size(), 0), vector<bool>(merchants.size(),0), items, merchants, solution, numMerchants);
    return solution;
}
