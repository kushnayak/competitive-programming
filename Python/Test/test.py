"""
ID: kushnay1
LANG: PYTHON3
TASK: test
"""
fins = open('test.in', 'r')
fouts = open('test.out', 'w')
x,y = map(int, fins.readline().split())
sum = x+y
fouts.write (str(sum)+ "\n")
fouts.close()