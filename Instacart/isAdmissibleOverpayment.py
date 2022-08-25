def solution(prices, notes, x):
    s = 0
    for i in range(len(prices)):
        if "Same" in notes[i]:
            continue
        diff = float(notes[i].split('%')[0])/100.0
        if 'higher' in notes[i]:
            factor = 1 + diff
            s += (prices[i]/factor)*diff
        else:
            factor = 1 - diff
            s -= (prices[i]/factor)*diff
    return s<=x
