from dataclasses import dataclass
from datetime import datetime

@dataclass
class OHLC:
    o: float
    h: float
    l: float
    c: float

def to_day(ts: int) -> str:
    return datetime.utcfromtimestamp(ts).strftime('%Y-%m-%d')
    
def solution(timestamp, instrument, side, price, size):
    result = []
    output = {}
    for i in range(len(timestamp)):
        ts = timestamp[i]
        p = price[i]
        day = to_day(ts)
        ticker = instrument[i]
        output.setdefault(day, {})
        output[day].setdefault(ticker, OHLC(p, p, p, p))
        output[day][ticker].h = max(output[day][ticker].h, p)
        output[day][ticker].l = min(output[day][ticker].l, p)
        output[day][ticker].c = p
    for day in sorted(output.keys()):
        for ticker in sorted(output[day].keys()):
            ohlc = output[day][ticker]
            o = "{:.2f}".format(ohlc.o)
            h = "{:.2f}".format(ohlc.h)
            l = "{:.2f}".format(ohlc.l)
            c = "{:.2f}".format(ohlc.c)
            result.append([day, ticker, o, h, l, c])
    return result
