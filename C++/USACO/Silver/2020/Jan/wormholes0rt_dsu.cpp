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
const int maxN = 1e5+5;
int N, M, arr[maxN];
struct edge { int a, b, w; };
vector<edge> edges;
struct DSU {
	int parent[maxN], size[maxN];
	void init() {forn(i,N) parent[i]=i, size[i]=1;}
	int find(int a) {return parent[a]==a ? a : parent[a]=find(parent[a]);}
	bool sameSet(int a, int b) {return find(a)==find(b); }
	void unite(int a, int b){
		a = find(a); b = find(b);
		// attaching to b to a where size[b] < size[a]
		if(a!=b){
			if(size[b]>size[a]) swap(a,b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
} dsu;

// check if swaps are posible with minw
bool check(int minw){
	dsu.init();
	for(auto u: edges)
		if(u.w>=minw){
			dsu.unite(u.a,u.b);
		}

	forn(i,N)
		if(!dsu.sameSet(i,arr[i])) 
			return false;
	return true;	
}

int search(){
	int pos=0, max=1e9+1;
	for(int a=max; a>=1; a/=2)
		while(check(pos+a)) pos += a;
	return pos;
}
int main() {
	IO("wormsort");
	bool ok = true;
	cin >> N >> M;
	forn(i,N){
		cin >> arr[i]; arr[i]--;
		if(arr[i]!=i) ok = false;
	}
	if(ok){
		cout << -1 << nl;
		return 0;
	}
	forn(i,M){
		int a, b, c; cin >> a >> b >> c; a--; b--;
		edges.pb({a,b,c});
	}
	cout << search() << nl;
}

