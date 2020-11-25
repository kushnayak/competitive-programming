"""
ID: kushnay1
LANG: PYTHON3
TASK: ride
"""

import string
alphabet_string = string.ascii_uppercase
alphabet_list = list(alphabet_string)
fin = open("ride.in","r")
fouts = open('ride.out', 'w')
comet = fin.readline()
comet = comet.rstrip('\n')
group = fin.readline()
group = group.rstrip('\n')
comet_list = list(comet)
group_list = list(group)
comet_total = 1
group_total = 1
for x in comet_list:
    position = alphabet_list.index(x) + 1
    comet_total *= position
for y in group_list:
    position1 = alphabet_list.index(y) + 1
    group_total *= position1
cometmod = comet_total % 47
groupmod = group_total % 47
if cometmod == groupmod:
    fouts.write("GO\n")
else:
    fouts.write("STAY\n")
fin.close()
fouts.close()