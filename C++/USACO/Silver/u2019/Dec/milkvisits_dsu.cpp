#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
#define pb push_back
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
const int maxN = 1e5+1;

struct DSU {
	int parent[maxN];
	int size[maxN];
	void init(int N) {forn(i,N) parent[i] = i, size[i] = 1;}
	int find(int s) {
		if(parent[s]==s) return s;
		else return parent[s] = find(parent[s]);
	}
	bool sameSet(int a, int b) {return find(a)==find(b);}
	bool unite(int a, int b) {
		a = find(a); b = find(b);
		if(a!=b){
			if(size[a]<size[b]) 
				swap(a,b);
			// attaching a to b where size[b] < size[a]
			parent[b] = a;
			size[a] += b;
			return true;
		}
		return false;
	}
}dsu;

int N, M;
string s;
vi adj[maxN];
char color[maxN];

void dfs(int node) {
	for (const auto& child: adj[node])
		if(color[node]==color[child] && dsu.unite(node,child))
			dfs(child);
}

int main() {
	IO("milkvisits");
	cin >> N >> M >> s;
	forn(i,N-1) {
		int a, b;
		cin >> a >> b;
		a--,b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	forn(i,N)
		color[i] = s[i];

	dsu.init(N);
	forn(i,N) {
		if(dsu.parent[i]==i)
			dfs(i);
	}

	// cout << nl;
	forn(i,M) {
		int a, b; char c;
		cin >> a >> b >> c;
		a--,b--;
		// cout << a << ' ' << b << " are in the same set " << dsu.sameSet(a,b) << nl;
		if(!dsu.sameSet(a,b))
			cout << 1;
		else 
			cout << (color[a]==c);
	}
	cout << nl;
}
