"""
ID: kushnay1
LANG: PYTHON3
TASK: beads
"""
bin = open('beads.in','r')
bout = open('beads.out','w')
length = int(bin.readline().strip())
bead = (bin.readline().strip())
def splitter(word,leng):
    word = list(word)
    totals = []
    if word == word[::-1]:
        return len(word)
    for x in range(leng):
        split1 = word[0:x+1]
        split2 = word.copy()
        del split2[0:x+1]
        comb1 = split2 + split1
        rev1 = list(reversed(split1))
        rev2 = list(reversed(split2))
        comb2 = rev1 + rev2
        same1 = 0
        same2 = 0
        color1 = comb1[0]
        color2 = comb2[0]
        print(comb1)
        print(comb2)
        for letter in comb1:
            if letter == color1:
                same1 += 1
            elif color1 == 'w' and letter != color1:
                color1 = letter
                same1 += 1
            elif color1 != 'w' and letter == 'w':
                same1 += 1
            else:
                break
        for letter in comb2:
            if letter == color2:
                same2 += 1
            elif color2 == 'w' and letter != color2:
                color2 = letter
                same2 += 1
            elif color2 != 'w' and letter == 'w':
                same2 += 1
            else:
                break
        total = same1 + same2
        totals.append(total)
    highest = max(totals)
    if highest > leng:
        highest = int(leng)
    return highest

highest = splitter(bead,length)
bout.write(str(highest)+'\n')
