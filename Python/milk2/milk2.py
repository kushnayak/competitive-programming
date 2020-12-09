"""
ID: kushnay1
LANG: PYTHON3
TASK: milk2
"""



milkin = open("milk2.in",'r')
farmers = int(milkin.readline().strip())

intervals = []
with open("milk2.in","r") as r:
    num = int(r.readline())
    for _ in range(num):
        p = list(map(int, r.readline().split()))
        intervals.append(p)

def writer(continous, idle):
    with open("milk2.out",'w') as m:
        m.write(str(continous) + " " + str(idle) + "\n")

sorted_intervals = sorted(intervals,key=lambda x:x[0])
print(sorted_intervals)

merged_list = []

interval_min = sorted_intervals[0][0]
interval_max = sorted_intervals[0][1]

if len(sorted_intervals) == 1:
    writer(sorted_intervals[0][1] - sorted_intervals[0][0],0)
    exit()
for i in range(1,len(sorted_intervals)):
    if interval_max >= sorted_intervals[i][0] >= interval_min:
        interval_max = max(sorted_intervals[i][1],interval_max)
    else:
        merged_list.append([interval_min,interval_max])
        interval_min = sorted_intervals[i][0]
        interval_max = sorted_intervals[i][1]
    if i == len(sorted_intervals) - 1:
        merged_list.append([interval_min,interval_max])

max_milking = 0
max_non_milking = 0

for i in range(len(merged_list)):
    length = merged_list[i][1] - merged_list[i][0]
    max_milking = max(length, max_milking)
    if not i == len(merged_list) - 1:
        non_milk_length = merged_list[i + 1][0] - merged_list[i][1]
        max_non_milking = max(non_milk_length, max_non_milking)
print(merged_list)
print(max_milking,max_non_milking)

writer(max_milking,max_non_milking)







