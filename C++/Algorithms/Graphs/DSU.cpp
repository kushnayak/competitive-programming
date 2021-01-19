
/*https://cp-algorithms.com/data_structures/disjoint_set_union.html
O(logn) per query for just path compression, amortized O(𝛼(n)) per query 
(worst case logn for query but on average constant time per call [inverse Ackermann function]) 
with union by size
*/
#include <bits/stdc++.h>
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxN = 10; // ** make sure maxN is upper bound **
// disjoint set data structure with path compression and union by size  
struct DSU {
	int parent[maxN], size[maxN], sets;
	void init(int N) {forn(i,N) parent[i] = i, size[i] = 1; sets = N;}
	int find(int s) {return parent[s]==s? s : parent[s] = find(parent[s]); }
	int sizeOf(int a){return size[find(a)]; } // returns size of set a 
	bool sameSet(int a, int b) {return find(a)==find(b);}
	int numSets() {return sets; } //returns the num of disjoint set, which starts off as N
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if(a!=b){ // attaching b -> a where size[b] < size[a]
			sets--;
			if(size[b]>size[a]) swap(a,b);
			parent[b] = a; 
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
