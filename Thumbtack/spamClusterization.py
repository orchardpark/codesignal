import re
from collections import deque

def jaccard(w1: set, w2: set):
    return float(len(w1.intersection(w2))) / len(w1.union(w2))
    
def solution(requests, ids, threshold):
    pattern = r'\w+'
    wordsPerId = {}
    for idx, request in enumerate(requests):
        words = set(map(lambda x: x.lower(), re.findall(pattern, request)))
        wordsPerId[ids[idx]] = words
    
    graph = {}
    for rId1 in wordsPerId:
        for rId2 in wordsPerId:
            if rId1 == rId2:
                continue
            graph.setdefault(rId1, set())
            graph.setdefault(rId2, set())
            w1 = wordsPerId[rId1]
            w2 = wordsPerId[rId2]
            if jaccard(w1, w2) >= threshold:
                graph[rId1].add(rId2)
                graph[rId2].add(rId1)
    
    visited = set()
    clusters = []
    while not len(visited) == len(ids):
        for rId in ids:
            if rId not in visited:
                cluster = []
                q = deque()
                q.append(rId)
                while len(q) > 0:
                    front = q.popleft()
                    if front in visited:
                        continue
                    cluster.append(front)
                    visited.add(front)
                    if front in graph:
                        for nId in graph[front]:
                            q.append(nId)
                if len(cluster) > 1:
                    clusters.append(sorted(cluster))
                break
    
    return sorted(clusters)
   
