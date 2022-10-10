def solution(inputString, width):
    result = ""
    idx = 0
    while idx < len(inputString):
        char = inputString[idx]
        window = inputString[max(0,idx-width): idx]
        if char in window:
            for length in range(min(len(window),len(inputString)-idx),0, -1):
                subs = inputString[idx:idx+length]
                if subs in window:
                    startIndex = window.find(subs)+idx-len(window)
                    result += f"({startIndex},{length})"
                    idx+=length
                    break
        else:
            result += char
            idx+=1
    return result
