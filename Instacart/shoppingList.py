import re
import functools
def solution(items):
    pattern = re.compile('[^\d+.]')
    items = re.sub(pattern, ' ', items)
    dotpattern = re.compile('[^\d](.)[^\d]')
    items = items.replace('..', '')
    numbers = items.split()
    return functools.reduce(lambda a,b: a+float(b), numbers, 0)
