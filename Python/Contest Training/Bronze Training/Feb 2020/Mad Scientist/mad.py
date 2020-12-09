#Flip all ranges of mismatching cows why did I not think of this soonetr


with open('breedflip.in', 'r') as b:
    num = int(b.readline().strip())
    ordered = b.readline().strip()
    not_order = b.readline().strip()
moves = 0

for index, (x,y) in enumerate(zip(ordered,not_order)):
    if index == 0:
        if x != y:
            moves += 1
    else:
        if x != y and not_order[index-1] == y and not_order[index-1] != ordered[index-1]:
            continue
        elif x != y and not_order[index-1] == ordered[index-1]:
                moves += 1


with open('breedflip.out', 'w') as b:
    b.write(str(moves) + '\n')