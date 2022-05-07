import re

def get_repr(i, subcode):
    segments = []
    degrees = 360 // len(subcode)
    pattern = re.compile('1+')
    for match in pattern.finditer(subcode):
        start = match.start()*degrees
        end = (match.start()+len(match.group()))*degrees
        segments.append([[i+1, start], [i+1, end]])
    
    if subcode[0] == '1' and subcode[-1] == '1' and len(segments)>=2:
        first = segments[0]
        segments[-1][1][1] += first[1][1]
        segments = segments[1:]
    return segments

def solution(userId):
    sol = []
    code = bin(int(userId)).replace('0b','').zfill(52)[::-1]
    
    first = code[:3]
    second = code[3:7]
    third = code[7:15]
    fourth = code[15:25]
    fifth = code[25:37]
    sixth = code[37:52]
    
    circonflex = [first, second, third, fourth, fifth, sixth]
    print(circonflex)
    
    for i,x in enumerate(circonflex):
        if '1' not in x:
            continue
        sol.extend(get_repr(i, x))
    
    return sol

