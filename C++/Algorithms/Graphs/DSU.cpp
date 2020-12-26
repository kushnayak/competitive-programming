#include <bits/stdc++.h>
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxN = 10;
// disjoint set data structure with path compression and union by size  
struct DSU {
	int parent[maxN], size[maxN], sets;
	void init(int N) {forn(i,N) parent[i] = i, size[i] = 1; sets = N;}
	int find(int s) {
		if(parent[s]==s) return s;
		else return parent[s] = find(parent[s]);
	}
	int sizeOf(int a){return size[find(a)]; } // returns size of set a 
	bool sameSet(int a, int b) {return find(a)==find(b);}
	int numSets() {return sets; } //returns the num of disjoint set which starts off asN
	void unite(int a, int b) {
		a = find(a); 
		b = find(b);
		if(a!=b){
			sets--;
			if(size[a]<size[b]) 
				swap(a,b);
			parent[b] = a; // attaching a to b where size[b] < size[a]
			size[a] += size[b];
		}
	}
}dsu;

int main() {
	dsu.init(5);
	dsu.unite(0,1);
	dsu.unite(1,2);
	dsu.unite(2,3);
	cout << dsu.numSets() << nl;
}
