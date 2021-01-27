#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define f first
#define s second
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

const int maxN=1e5+5;
int N, M, order[maxN]; 
vector<pii> adj[maxN];

bool check(int k){
	dsu.init(N);
	for(int i=0; i<N; i++)
		for(auto &u: adj[i])
			if(u.s>=k)
				dsu.unite()
}
void bsearch(){
	int pos=0, max=1e9+5;
	for(int a=max; a>=1; a/=2)
		while(check(pos+a)) 
			pos+=a;
	return pos;
}
int main() {
	IO("wormsort");
	cin >> N >> M; forn(i,N) cin >> order[i], --order[i];
	forn(i,M){
		int a, b, k; cin >> a >> b >> k; a--; b--;
		adj[a].pb({b,k}); adj[b].pb({a,k});
	}

}

