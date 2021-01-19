#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define fore(i,l,r) for(int i=l;i<r;i++)

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 2e5;

struct DSU {
	int parent[maxN], size[maxN], sets;
	DSU(int N) {forn(i,N) parent[i] = i, size[i] = 1; sets = N;}
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
};

void solve() {
	int N;
	cin >> N;
	DSU dsu(N);
	forn(i,N) {
		int a; cin >> a; a--;
		dsu.unite(i,a);
	}
	forn(i,N) {
		cout << dsu.sizeOf(i);
		i==N-1 ? cout << nl : cout << " ";
	}

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--) {
		solve();
	}
	
}
