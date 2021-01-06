#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second 
using namespace std;
using pii = pair<int,int>;
const int MAX = int(1e9)+5;

/* we can represent the connections and relevance in a weighted undirected tree;
   to answer each query all we need to do is dfs the node, track the minimum weight along
   each path, and check if the relevance (min weight) is ≥ k

*/
int N, Q;
vector<pii> adj[5005];
bool visited[5005];
int valid = 0;

void dfs(int s, int min_w, int k) {
	if (visited[s]) return;
	visited[s] = true;
	if (min_w>=k&& min_w!=MAX) valid++;
	// cout << "visited node " << s << " with min w " << min_w << nl;
	for (auto u: adj[s]) {
		dfs(u.f, min(u.s,min_w), k);
	}
}
int main() {
	IO("mootube");
	cin >> N >> Q;
	forn(i,N-1) {
		int a, b, r;
		cin >> a >> b >> r;
		a--, b--;
		adj[a].pb(pii(b,r));
		adj[b].pb(pii(a,r));
	}
	
	// forn(i,N) {
	// 	cout << "Edges to node " << i << nl;
	// 	for (auto u: adj[i])
	// 		cout << "Node " << u.f << " with weight " << u.s << nl;
	// }
	forn(i,Q) {
		int k, v;
		cin >> k >> v;
		v--;
		dfs(v, MAX, k);
		cout << valid << nl;
		valid = 0;
		memset(visited, 0, N);
	}
}
