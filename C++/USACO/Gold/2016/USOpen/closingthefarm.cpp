#include <bits/stdc++.h>
#define IO(f) ios_base::sync_with_stdio(0); cin.tie(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

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

const int maxN = 2e5+5; //change maxN if submitting to gold

struct DSU {
	int parent[maxN];
	int size[maxN];
	int sets;
	void init(int N) {forn(i,N) parent[i] = i, size[i] = 1; sets=N; }
	int find(int s) {
		if(parent[s]==s) return s;
		else return parent[s] = find(parent[s]);
	}
	int sizeOf(int a){return size[find(a)]; }
	int numSets(){return sets;}
	void unite(int a, int b) {
		a = find(a); b = find(b);
		if(a!=b){
			sets--;
			if(size[a]<size[b]) swap(a,b);
			// attaching b -> a where size[b] < size[a]
			parent[b] = a;
			size[a] += b;
		}
	}
}dsu;

int N, M;
vi adj[maxN];
int open[maxN];
bool seen[maxN];
vi ok;


int main() {
	IO("closing");
	cin >> N >> M;
	forn(i,M){
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i=N-1; i>=0; i--) {
		int a; cin >> a; a--;
		open[i] = a;
	}
	int comp = N;
	dsu.init(N);
	forn(i,N) {
		seen[open[i]] = true;
		for(auto u: adj[open[i]])
			if(seen[u])
				dsu.unite(open[i],u);
		ok.pb((comp==dsu.numSets()));
		comp--;
	}

	for(int i=ok.size()-1; i>=0; i--) {
		if(ok[i])
			cout << "YES" << nl;
		else 
			cout << "NO" << nl;
	}
}

