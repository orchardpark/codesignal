import os
import pandas as pd

logdir = '/root/devops/logs'
errors = {}
for fname in (os.listdir(logdir)):
    if fname.endswith('.log'):
        fpath = os.path.join(logdir, fname)
        with open(fpath) as fin:
            for line in fin.readlines():
                #print(line)
                tokens = line.split("|")
                if len(tokens)> 2 and tokens[1] == "ERROR":
                    name = tokens[2]
                    if name not in errors:
                        errors[name] = 0
                    errors[name] += 1
                
class Item:
    def __init__(self, name, count):
        self.name = name
        self.count = count
    
    def __gt__(self, other):
        if self.count == other.count:
            return self.name > other.name
        return self.count < other.count
    
items = [Item(i[0],i[1]) for i in errors.items()]
items.sort()
for item in items:
    print(item.name, item.count
