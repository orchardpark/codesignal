from dataclasses import dataclass
import operator

@dataclass
class Task:
    name: str
    start_date: str
    end_date: str
    people: list
    

def date_in_task(day: str, task: Task)->bool:
   return task.start_date <= day and day <= task.end_date 

def solution(tasks, queries):
    result = []
    
    for query in queries:
        person = query[0]
        day = query[1]
        worked_tasks = []
        for task in tasks:
            t = Task(task[0], task[1], task[2], task[3:])
            if date_in_task(day, t) and person in t.people:
                worked_tasks.append(t)
        sorted_working_tasks = sorted(worked_tasks, key=operator.attrgetter("end_date","name"))
        result.append(list(map(lambda t: t.name, sorted_working_tasks)))
         
    
    return result
        
