with open('triangles.in', 'r') as t:
    num = int(t.readline())
    points = [list(map(int,t.readline().split())) for x in range(num)]
# print(points)

def possible_ar(point,listofpoints):
    total = []
    for x in listofpoints:
        if point[1] == x[1] and x != point:
            # print(f"The point {point} and possible {x}")
            for z in listofpoints:
                # print(f"The point {point} and possible {x}")
                if (point[0] == z[0]) and (x != z and point != z):
                    # print(f"Possible case 1: Point:{point}  X::{x}  Z:{z}")
                    total.append(abs(point[1] - z[1]) * abs(point[0] - x[0]))
                if x[0] == z[0] and (x != z and point != z):
                    # print(f"Possible case 2: Point:{point}  X::{x}  Z:{z}")
                    total.append(abs(point[0] - x[0]) * abs(x[1] - z[1]))
                # print(point,x,z)
    return total

possible_area = []

for x in points:
     possible_area.append(possible_ar(x,points))

with open('triangles.out', 'w') as t:
    t.write(str(max([a for x in possible_area for a in x])) + '\n')


