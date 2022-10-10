string solution(vector<int> seq, vector<char> fragmentData, int n) {
    int lastSequenceNumber = *max_element(seq.begin(), seq.end());
    map<int, map<char, int>> mapping;
    for(int i=0; i<fragmentData.size(); i++)
    {
        int sequenceNumber = seq[i];
        int fragment = fragmentData[i];
        if(mapping.find(sequenceNumber)==mapping.end())
        {
            mapping[sequenceNumber]=map<char,int>();
        }
        if(mapping[sequenceNumber].find(fragment)==mapping[sequenceNumber].end())
        {
            mapping[sequenceNumber][fragment]=0;
        }
        mapping[sequenceNumber][fragment]++;
    }
    stringstream ss;
    int prevSeqNumber = -1;
    for(auto& sequenceMapping : mapping)
    {
        for(auto& fragmentMapping : sequenceMapping.second)
        {
            if(fragmentMapping.second*2 > n) 
            {
                if(
                    (sequenceMapping.first == lastSequenceNumber && fragmentMapping.first != '#') || 
                    (sequenceMapping.first != lastSequenceNumber && fragmentMapping.first == '#')
                    ) return "";
                if(prevSeqNumber != -1 && sequenceMapping.first-prevSeqNumber!=1) return "";
                prevSeqNumber = sequenceMapping.first;
                ss << fragmentMapping.first;
                break;
            }
        }
    }
    string reconstruction = ss.str();
    if(reconstruction.size()<mapping.size()) return "";
    
    
    return reconstruction;

}
