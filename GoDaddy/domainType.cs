string[] solution(string[] domains) {
    return domains.Select(x=>Label(x)).ToArray();

}
string Label(string domain)
{
    var end = domain.Split('.').Last();
    switch(end)
    {
        case "org":
            return "organization";
        case "com":
            return "commercial";
        case "net":
            return "network";
        case "info":
            return "information";
        default:
            return "unknown";
    }

