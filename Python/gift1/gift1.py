"""
ID: kushnay1
LANG: PYTHON3
TASK: gift1
"""
fin = open("gift1.in",'r')
total = int(fin.readline().strip())
money = {}
monne = []
for x in range(total):
    person = fin.readline().strip()
    monne.append(person)
    money[person] = 0
while True:
    giver = fin.readline().strip()
    if giver == "":
        break
    amount, many = map(int, fin.readline().strip().split())
    recipients = []
    for x in range(many):
        recipient = fin.readline().strip()
        recipients.append(recipient)
    if 0 in [amount,many]:
        continue
    money[giver] -= amount - amount % many
    for name in recipients:
        money[name] += amount // many

fout = open('gift1.out','w')
for name in monne:
    fout.write(name + ' ' + str(money[name]) + "\n")