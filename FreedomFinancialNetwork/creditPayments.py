import re
class Payment:
    def __init__(self, paymentDay, amount):
        self.paymentDay = int(paymentDay)
        self.amount = int(amount)
    
    def on_time(self):
        return self.paymentDay <= 15
    
    def __str__(self):
        return "{} - {}".format(self.paymentDay, self.amount)
        

class Date:
    def __init__(self, month, year):
        self.month = int(month)
        self.year = int(year)
    
    def increment(self):
        if self.month == 12:
            self.month = 1
            self.year +=1
        else:
            self.month += 1
    
    def prevMonth(self):
        if self.month == 1:
            return Date(12, self.year-1)
        else:
            return Date(self.month-1, self.year)
    
    def __le__(self, other):
        if self.year == other.year:
            return self.month <= other.month
        else:
            return self.year <= other.year
    
    def __eq__(self, o):
        return self.year==o.year and self.month == o.month
    
    def __hash__(self):
        return hash((self.year, self.month))
            
    def __str__(self):
        return "{}/{}".format(self.month, self.year)

def solution(a, b, startDate, endDate, history):
    res = []
    
    # parse start and end date
    monthYearPattern = re.compile('(\d\d)/(\d\d\d\d)')
    startMatch = re.search(monthYearPattern, startDate)
    startYear = startMatch.group(2)
    startMonth = startMatch.group(1)
    start = Date(startMonth, startYear)
    
    endMatch = re.search(monthYearPattern, endDate)
    endYear = endMatch.group(2)
    endMonth = endMatch.group(1)
    end = Date(endMonth, endYear)
    
    # parse history
    historyMap = {}
    for payment in history:
        paymentAmount = re.search('\$(\d+)', payment).group(1)
        paymentDate = re.search('(\d\d)/(\d\d)/(\d\d\d\d)', payment)
        paymentDay = paymentDate.group(2)
        paymentMonth = paymentDate.group(1)
        paymentYear = paymentDate.group(3)
        historyMap[Date(paymentMonth, paymentYear)] = Payment(paymentDay, paymentAmount)
    
    currentDate = start
    monthCount = 0
    currentb = b
    while(currentDate <= end):
        if monthCount < 2:
            res.append(f"Leave as it is, {b}.")
        else:
            secondMonth = currentDate.prevMonth()
            firstMonth = secondMonth.prevMonth()
            
            totalPaid = historyMap.get(currentDate, Payment(16,0)).amount + \
                historyMap.get(secondMonth, Payment(16,0)).amount + \
                historyMap.get(firstMonth, Payment(16,0)).amount
            latePayments = (not historyMap.get(currentDate, Payment(16,0)).on_time()) + \
                (not historyMap.get(secondMonth, Payment(16,0)).on_time()) + \
                (not historyMap.get(firstMonth, Payment(16,0)).on_time())
            notPaidInLastTwo = currentDate not in historyMap and secondMonth not in historyMap
            hasPaidDouble = historyMap.get(currentDate, Payment(16,0)).amount >= 2*currentb and \
                historyMap.get(secondMonth, Payment(16,0)).amount >= 2*currentb and \
                historyMap.get(firstMonth, Payment(16,0)).amount >= 2*currentb
                
            # check if we need to add one year
            if totalPaid < 3*currentb or latePayments == 3 or notPaidInLastTwo:
                currentb = round(currentb + a * (1 /100.0))
                res.append(f'Add one year, {currentb}.')
            # check if we need to decrease one year
            elif hasPaidDouble:
                currentb = round(currentb - a * (1 /100.0))
                res.append(f'Remove one year, {currentb}.')
            # leave it, just get me the lamb sauce!
            else:
                res.append(f"Leave as it is, {currentb}.")
                
        currentDate.increment()
        monthCount+=1
    return res

