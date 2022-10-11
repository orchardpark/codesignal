unsigned int edit_distance(const std::string& s1, const std::string& s2)
{
	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      // note that std::min({arg1, arg2, arg3}) works only in C++11,
                      // for C++98 use std::min(std::min(arg1, arg2), arg3)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

double euclidean_distance(vector<int> object)
{
    if(object.size()==2)
        return sqrt(object[0]*object[0]+object[1]*object[1]);
    else if(object[0]!=object[2] && object[0]<0 && object[2]>=0)
        return sqrt(object[1]*object[1]);
    else if(object[0]!=object[2] && object[0]>0)
        return sqrt(object[0]*object[0]+object[1]*object[1]);
    else if(object[0]!=object[2] && object[2]<0)
        return sqrt(object[2]*object[2]+object[1]*object[1]);
    else if(object[1]!=object[3] && object[1]<0 && object[3]>=0)
        return sqrt(object[0]*object[0]);
    else if(object[1]!=object[3] && object[1]>0)
        return sqrt(object[0]*object[0]+object[1]*object[1]);
    else if(object[1]!=object[3] && object[3]<0)
        return sqrt(object[2]*object[2]+object[3]*object[3]);
    return 99999;
}

string to_lowercase(string input)
{
    auto data=input;
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return data;
}

string solution(string address, vector<vector<int>> objects, vector<string> names) {
    double minDistance = INT_MAX;
    string minObject = "nope";
    for(int i=0; i<names.size(); i++)
    {
        string prefix = names[i].substr(0, min(names[i].size(), address.size()));
        string prefixL = names[i].substr(0, min(names[i].size(), address.size()-1));
        string prefixR = names[i].substr(0, min(names[i].size(), address.size()+1));
        if(
            edit_distance(to_lowercase(address), to_lowercase(prefix))<=1
            || edit_distance(to_lowercase(address), to_lowercase(prefixL))<=1
            || edit_distance(to_lowercase(address), to_lowercase(prefixR))<=1
            
            )
        {
            double distance = euclidean_distance(objects[i]);
            if(distance < minDistance)
            {
                minDistance = distance;
                minObject = names[i];
            }
        }
    }
    return minObject;
}
