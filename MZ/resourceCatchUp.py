import datetime
def solution(logOut, logIn):
    start = datetime.datetime.utcfromtimestamp(logOut[0])
    end = datetime.datetime.utcfromtimestamp(logIn[0])
    foodDiff = logOut[1]-logIn[1]
    startDown = datetime.datetime(start.year,start.month, start.day, start.hour, 0, 0)
    if end.minute == 0 and end.second == 0:
        endDown = end
    else:
        endDown = datetime.datetime(end.year,end.month, end.day, end.hour, 0, 0)+datetime.timedelta(hours=1)
    
    return foodDiff / ((endDown-startDown).total_seconds()/3600 - 1)
