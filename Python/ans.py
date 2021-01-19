class DSU:
	parent = []
	size = []
	def __init__(self, N):
		self.sets = N
		for i in range(N):
			self.parent.append(i)
			self.size.append(1)
	def find(self, a):
		if a != self.parent[a]:
			self.parent[a] = self.find(self.parent[a])
		return self.parent[a]
	def same_set(self, a, b):
		return self.find(a) == self.find(b)
	def unite(self, a, b):
		a = self.find(a)
		b = self.find(b)
		if a!=b:
			if self.size[b] > a:
				temp = b
				b = a
				a = temp
			self.parent[b] = a
			self.size[a] += self.size[b]
			self.sets -= 1
class edge:
	def __init__(self, a, b, w):
		self.a = a
		self.b = b
		self.w = w
with open("input.txt","r") as fin:
	N,M = map(int, fin.readline().split())
	order = list(map(lambda x: int(x)-1,fin.readline().split()))
	edges = []
	for i in range(M):
		a,b,w = map(int, fin.readline().split())
		edges.append(edge(a-1,b-1,w))


def check(K):
	dsu = DSU(N)
	for u in edges:
		if u.w >= K:
			dsu.unite(u.a, u.b)
	for i in order:
		if not dsu.same_set(i,order[i]):
			return False
	return True


l = 0 
r = 1e9+1
while(l<r):
	mid = (l+r+1)//2
	if check(mid): r = mid
	else: mid-


