def solution(stations):
    import requests
    from math import radians, cos, sin, asin, sqrt
    import itertools
    import time
    positions = {}
    
    def find_closest_match(station, members):
        
        first_member = None
        for i, member in enumerate(members):
            if member['type']=='train_station' and member['name']==station:
                return member
            elif member['type']=='train_station':
                if not first_member:
                    first_member = member
        return first_member
                
    def euclidean(lat1, lon1, lat2, lon2):
        return math.sqrt((lat1-lat2)**2+(lon1-lon2)**2)
    
    session = requests.Session()
    results = {}
    start = time.time()
    for station in stations:
        res = session.get(url="https://transportapi.com/v3/uk/places.json",params={"query": station, "type": "train_station", "app_id": "8b9cd4d9", "app_key": "69eaf54e2f7d2f279a03077acab2721b"}).json()
        members = res['member']
        train_station = find_closest_match(station, members)
        latitude = train_station['latitude']
        longitude = train_station['longitude']
        positions[station] = (latitude, longitude)
    
    print("Request time", time.time()-start)
    
    
    minDist = 9999999999
    for combination in itertools.combinations(stations,2):
        lat1, lon1 = positions[combination[0]]
        lat2, lon2 = positions[combination[1]]
        dist = euclidean(lon1, lat1, lon2, lat2)
        minDist = min(minDist, dist)
        
    
    return minDist
