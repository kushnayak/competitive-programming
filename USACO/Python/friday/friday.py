"""
ID: kushnay1
LANG: PYTHON3
TASK: friday
"""
f = open('friday.in','r')
w = open('friday.out','w')


def frequency(week_list,year,x):
    month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if year%4==0 and year%100!=0:
        month[1] = 29
    elif year%400 == 0:
        month[1] = 29
    weekday = x
    for time in range(12):
        weekday = (weekday+13)%7
        week_list[weekday] += 1
        weekday = (weekday + (month[time]-13))%7
    return week_list, weekday

week_list1 = [0,0,0,0,0,0,0]
weekday1 = 1
n = int(f.read())
for time in range(1900,1900 + n):
    week_list1,weekday1 = frequency(week_list1,time,weekday1)
for x in range(6):
    w.write(str(week_list1[x])+" ")
w.write(str(week_list1[6])+"\n")
