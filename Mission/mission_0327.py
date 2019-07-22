data = [
    {'name' : 'Bale', 'age' : 29},
    {'name' : 'Mbappe', 'age' : 20},
    {'name' : 'Gerrard', 'age' : 38},
    {'name' : 'Messi', 'age' : 31},
    {'name' : 'Ronaldo', 'age' : 34},
    {'name' : 'Neymar', 'age' : 27},
    {'name' : 'Aguero', 'age' : 30},
    {'name' : 'Kevin', 'age' : 27},
    {'name' : 'Son', 'age' : 26},
    {'name' : 'Pogba', 'age' : 26},
    {'name' : 'Park', 'age' : 38},
    {'name' : 'Silva', 'age' : 33},
    {'name' : 'Hazard', 'age' : 28},
    {'name' : 'Alonso', 'age' : 37},
    {'name' : 'Rodriguez', 'age' : 27},
    {'name' : 'Robben', 'age' : 35},
    {'name' : 'Ozil', 'age' : 30},
    {'name' : 'Modric', 'age' : 33},
    {'name' : 'Rakitic', 'age' : 31},
    {'name' : 'Suarez', 'age' : 32}
]

a=int(raw_input('Choose - 20s or 30s (2 or 3) ? '))
b=raw_input('First letter of name (Uppercase) ? ')
list1 = []

def sort() :
    for i in data :
        if i['age'] / 10 == a :
            if i['name'][0] == b :
                list1.append(i)
                print i
    if len(list1) == 0 :
        print 'No such person'
sort()
