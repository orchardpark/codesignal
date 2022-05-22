class DomainScore:
    def __init__(self, domain):
        self.domain = domain
        self.score = 0
    
    def increment(self):
        self.score += 20
        
    def bonus_space(self):
        if self.score < 100:
            return 0
        elif self.score < 200:
            return 3
        elif self.score < 300:
            return 8
        elif self.score < 500:
            return 15
        else:
            return 25
    
    def __lt__(self, o):
        if self.bonus_space() == o.bonus_space():
            return self.domain < o.domain
        else:
            return self.bonus_space() > o.bonus_space()

def solution(emails):
    domains = {}
    for email in emails:
        domain = email.split('@')[1]
        domains.setdefault(domain, DomainScore(domain))
        domains[domain].increment()
    
    return list(map(lambda x: x.domain, sorted(domains.values())))

