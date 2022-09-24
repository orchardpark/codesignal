from collections import deque
from datetime import datetime, timedelta

def has_overlap(shopper, order, lead_time):
    shopper_start = datetime.strptime(shopper[0], '%H:%M')
    shopper_end = datetime.strptime(shopper[1], '%H:%M')
    order_start = datetime.strptime(order[0], '%H:%M')
    order_end = datetime.strptime(order[1], '%H:%M')
    
    return shopper_start <= order_end and order_start <= shopper_end and max(order_start, shopper_start)+timedelta(minutes=lead_time) <= min(order_end, shopper_end)
    
    
def bfs(graph, start, end, parent):
    visited = [False]*len(graph)
    queue = deque()
    queue.append(start)
    visited[start] = True
    
    while queue:
        u = queue.popleft()
        for n in graph[u]:
            if not visited[n]:
                queue.append(n)
                visited[n] = True
                parent[n] = u
                if n == end:
                    return True
    return False
    
    
def ford_fulkerson(graph, start, end):
    parent = [-1]*len(graph)
    max_flow = 0
    while bfs(graph, start, end, parent):
        path_flow = 1
        max_flow += path_flow
        v = end
        while v is not start:
            u = parent[v]
            graph[u].remove(v)
            graph[v].add(u)
            v = parent[v]
            
    return max_flow

def solution(shoppers, orders, leadTime):
    # create flow graph
    s = len(shoppers)+len(orders)
    e = s + 1
    graph = {}
    graph.setdefault(s , set(list(range(len(shoppers)))))
    graph.setdefault(e, set())
    for idx in range(len(shoppers)):
        graph[idx] = set()
    for jdx in range(len(orders)):
        graph[jdx+len(shoppers)] = set([e])
        
    for idx, shopper in enumerate(shoppers):
        for jdx, order in enumerate(orders):
            if has_overlap(shopper, order, leadTime[jdx]):
                graph[idx].add(jdx+len(shoppers))
                
    # compute max flow
    flow = ford_fulkerson(graph, s, e)
    return flow == len(orders)
