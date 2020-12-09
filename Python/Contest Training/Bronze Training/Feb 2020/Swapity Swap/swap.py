with open('swap.in','r') as s:
    n,k = map(int,s.readline().split())
    a1,a2 = map(int,s.readline().split())
    b1, b2 = map(int, s.readline().split())
order = list(range(1,n+1))
a1 -= 1
a2 -= 1
b1 -= 1
b2 -= 1

length = len(order)
for _ in range(k):
    order[a1:a2+1] = order[-1*(length-a2):-1*(length-a1)-1:-1]
    order[b1:b2 + 1] = order[-1 * (length - b2):-1 * (length - b1) - 1:-1]

with open('swap.out','w') as s:
    for x in order:
        s.write(str(x) + '\n')

