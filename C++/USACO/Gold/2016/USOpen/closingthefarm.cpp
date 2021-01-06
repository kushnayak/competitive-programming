#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 200005;
int N, M; 
open[maxN];
vi adj[maxN];
struct DSU {
	int parent[maxN], size[maxN], sets;
	void init(int N) {forn(i,N) parent[i] = i, size[i] = 1; sets = N;}
	int find(int s) {return parent[s]==s? s : parent[s] = find(parent[s]); }
	int sizeOf(int a){return size[find(a)]; } // returns size of set a 
	bool sameSet(int a, int b) {return find(a)==find(b);}
	int numSets() {return sets; } //returns the num of disjoint set which starts off asN
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if(a!=b){
			sets--;
			if(size[a]<size[b]) swap(a,b);
			parent[b] = a; // attaching b -> a where size[b] < size[a]
			size[a] += size[b];
		}
	}
}dsu;


int main() {
	IO("closing");
	cin >> N >> M;
	forn(i,M){
		int a,b; cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	for(int i=N-1; i>=0; i--){
		int a; cin >> a; 
		open[i] = --a;
	}
	int comp = N;
	forn(i,N){
		comp--;
		for(auto u: adj[open[i]]) if(open[u])
			dsu.unite(open[i],)
	}
}	

