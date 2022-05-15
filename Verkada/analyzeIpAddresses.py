import os

root_dir = '/root/data/'
ips = []
files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(root_dir) for f in filenames]

for f in files:
    with open(f) as fin:
        text = fin.read()
        for match in text.replace('\n', ' ').replace(',', ' ').split():
            tokens = match.split('.')
            if len(tokens)==4 and all([0<=int(token)<=255 for token in tokens]):
                ips.append(match)
        

for ip in sorted(list(set(ips))):
    print(ip)
