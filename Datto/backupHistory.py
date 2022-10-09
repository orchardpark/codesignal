def solution(creationTimes, backupRequests, k, t):
    numBackups = [0]*len(creationTimes)
    backupRequests = sorted(backupRequests, key=lambda x: x[2])
    for i in range(len(creationTimes)):
        currentTime = creationTimes[i]
        relevantBackups = [bk for bk in backupRequests if bk[1]==i]
        cancellationTime = -1
        for backup in relevantBackups:
            if backup[2]<=t:
                if backup[0]==0:
                    if cancellationTime == -1:
                        cancellationTime = backup[2]
                elif backup[0]==1:
                    if (cancellationTime != -1 and backup[2]>=cancellationTime) or (backup[2]-creationTimes[i])%k!=0 or backup[2]==creationTimes[i]:
                        numBackups[i]+=1
        if t<=creationTimes[i] or (cancellationTime != -1 and cancellationTime<=creationTimes[i]):
            pass
        elif cancellationTime == -1:
            numBackups[i]+= (t-creationTimes[i])//k
        else:
            numBackups[i]+= (cancellationTime-creationTimes[i]-1)//k
                       
    return numBackup
