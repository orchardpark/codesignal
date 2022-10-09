import statistics
def solution(orders, n):
    stats = []
    for i in range(n):
        to = -n+i+1 if -n+i+1 <0 else len(orders)
        arr = orders[-n:to]
        try:
            stdval = statistics.stdev(arr)
        except statistics.StatisticsError:
            stdval = -1
        stats.append([max(arr), statistics.mean(arr), stdval])
        
        
    return stats
