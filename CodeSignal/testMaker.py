import re
def solution(source, challengeId):
    newSource = []
    for idx, line in enumerate(source):
        pattern = re.compile(r'( *)//DB (\d+)//')
        match = re.match(pattern, line)
        if match:
            debugIndex = int(match.group(2))
            if debugIndex == challengeId:
                newLine = match.group(1)+re.sub(pattern,"",line)
                newSource[len(newSource)-1] = newLine
        else:
            newSource.append(line)
    return newSource

