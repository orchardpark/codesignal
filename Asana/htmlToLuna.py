try: 
    from BeautifulSoup import BeautifulSoup
except ImportError:
    from bs4 import BeautifulSoup

def get_leaf_luna(tag: str):
    if tag == 'div':
        return 'DIV([])'
    elif tag == 'p':
        return 'P([])'
    elif tag == 'b':
        return 'B([])'
    else:
        return 'IMG({})'
        
def get_internal_luna(tag: str, innerLuna: list):
    if tag == 'div':
        return 'DIV([{}])'.format(", ".join(innerLuna))
    elif tag == 'p':
        return 'P([{}])'.format(', '.join(innerLuna))
    elif tag == 'b':
        return 'B([{}])'.format(', '.join(innerLuna))
    elif tag == 'img':
        return 'IMG({})'
    else:
        return "".join(innerLuna)

def get_luna(html):
    children = html.findChildren(recursive=False)
    if len(children) == 0:
        return get_leaf_luna(html.name)
    else:
        innerLuna = []
        for child in children:
            innerLuna.append(get_luna(child))
        internal = get_internal_luna(html.name, innerLuna)
        return internal
        

def solution(html):
    if html == "":
        return ""
    parsed_html = BeautifulSoup(html)
    return get_luna(parsed_html)

