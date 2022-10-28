string toDay(int timestamp)
{
    time_t ts = timestamp;
    auto t =  asctime(gmtime(&ts));
    stringstream ss;
    ss << t;
    string day;
    string acc;
    string trash;
    ss >> day;
    acc += day;
    ss >> day;
    acc += day;
    ss >> day;
    acc += day;
    ss >> trash;
    ss >> day;
    acc += day;
    return acc;
}

void resetAllowances(map<int, int>& allowancePerUser, int startingAllowance)
{
    for(auto &it : allowancePerUser)
    {
        it.second=startingAllowance;
    }
}

vector<int> solution(vector<vector<int>> sentBatches, vector<vector<int>> receivedMessages, int startingAllowance) {
    int i=0;
    int j = 0;
    map<int, int> allowancePerUser;
    set<int> failedBatches;
    for(auto& batch : sentBatches)
    {
        for(int k=1; k<batch.size(); k++){
            if(allowancePerUser.find(batch.at(k))==allowancePerUser.end())
            {
                allowancePerUser[batch.at(k)]=startingAllowance;
            }
        }
    }
    for(auto &message : receivedMessages)
    {
        if(allowancePerUser.find(message[1]) == allowancePerUser.end())
        {
            allowancePerUser[message.at(1)]=startingAllowance;
        }
    }
    int prevTimestamp = -1;
    while(i<sentBatches.size())
    {
        if(prevTimestamp!=-1)
        {
            int currentTimestamp;
            if(j<receivedMessages.size() && receivedMessages[j][0]<=sentBatches[i][0])
                currentTimestamp = receivedMessages[j][0];
            else
                currentTimestamp = sentBatches[i][0];
            if(toDay(currentTimestamp)!=toDay(prevTimestamp))
            {
                resetAllowances(allowancePerUser, startingAllowance);
            }
        }
        if(j<receivedMessages.size() && receivedMessages[j][0]<=sentBatches[i][0])
        {
            auto &message = receivedMessages[j];
            allowancePerUser[message[1]]++;
            prevTimestamp = receivedMessages[j][0];
            j++;
        }
        else
        {
            prevTimestamp = sentBatches[i][0];
            auto &batch = sentBatches[i];
            bool failed = false;
            for(int k=1; k<batch.size() && !failed; k++)
            {
                int user = batch[k];
                if(allowancePerUser[user]==0) {
                failed=true;
                }
            }
            if(failed)
            {
                failedBatches.insert(i);
            }
            else{
                for(int k=1; k<batch.size() && !failed; k++)
            {
                int user = batch[k];
                allowancePerUser[user]--;
            }
            }
            i++;
        }
    }
    vector<int> result;
    for(int b : failedBatches) result.emplace_back(b);
    return result;
}
