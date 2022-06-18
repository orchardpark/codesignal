set<string> squatDomains(string domain)
{
    set<string> res;
    int n = domain.size();
    for(int i=0; i<n-1; i++)
    {
        if(domain[i]=='.' || domain[i+1]=='.') continue;
        string cpy = domain;
        char tmp = cpy[i];
        cpy[i] = cpy[i+1];
        cpy[i+1] = tmp;
        res.insert(cpy);
    }
    return res;
}

int solution(int n, string domain) {
    int k=0;
    set<string> allDomains;
    set<string> newDomains;
    allDomains.insert(domain);
    newDomains.insert(domain);
    int prevSize = 1;
    while(true)
    {
        set<string> tmp;
        for(auto& d : newDomains)
        {
            auto squats = squatDomains(d);
            tmp.insert(squats.begin(), squats.end());
        }
        allDomains.insert(tmp.begin(), tmp.end());
        newDomains = tmp;
        if(allDomains.size()==prevSize) return -1;
        prevSize = allDomains.size();
        if(allDomains.size()-1>n) break;
        k++;
    }
    return k;

}
