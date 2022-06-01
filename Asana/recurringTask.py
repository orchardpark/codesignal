import datetime

def solution(firstDate, k, daysOfTheWeek, n):
    sol = []
    first = datetime.datetime.strptime(firstDate, '%d/%m/%Y')
    firstMeetingDate = first if first.strftime("%A") in daysOfTheWeek  else None
    sol.append(first.strftime('%d/%m/%Y'))
    currentDate = first+datetime.timedelta(days=1)
    num_meetings=1
    # perform week
    while(len(sol)<n):
        # get other weekdays
        while num_meetings < len(daysOfTheWeek) and len(sol) < n:
            if currentDate.strftime("%A") in daysOfTheWeek:
                if firstMeetingDate is None:
                    firstMeetingDate = currentDate
                sol.append(currentDate.strftime('%d/%m/%Y'))
                num_meetings+=1
            currentDate += datetime.timedelta(days=1)
        num_meetings = 0
        # get next first day
        currentDate = firstMeetingDate + datetime.timedelta(weeks=k)
        firstMeetingDate = None
        
                
    return sol
   
