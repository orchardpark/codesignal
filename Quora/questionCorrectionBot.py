import re

def capitalize(match):
    return match.group(1) + match.group(2).upper()

def solution(question: str):
    # strip whitespace
    question = question.strip()
    question = re.sub(' +', ' ', question)
    # fix spacing around punctuation
    question = re.sub(r'(,)([^\s])', r'\1 \2', question)
    question = re.sub(r' (,)', r'\1', question)
    # start each with capital
    question = re.sub(r"^([^\w]*)(\w)", capitalize, question)
    # end with single question mark
    if question[-1] != '?':
        if len(question)>=1 and (question[-1]==','):
            question += " ?"
        else:
            question += '?'
    question = re.sub('(\?+)$', '?', question)
    
    
    return question
