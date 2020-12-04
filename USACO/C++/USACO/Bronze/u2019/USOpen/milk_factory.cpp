#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define pb push_back
using namespace std;


vector<int> adj[100];
bool visited[100];
int N;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u: adj[s])
		dfs(u);

}
int main() {
	IO("factory");

	cin >> N;
	forn(i,N-1) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
	}

	int ans = -1;
	bool found = false;
	// i target node loop through dfs j nodes
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i==j) continue;
			dfs(j);
			if (visited[i]) {found = true; memset(visited, 0, N);}
			else {found = false; break;}
		}
		if (found){
			ans = i+1;
			break;
		}
		memset(visited, 0, N);
	}

	cout << ans << nl;
	
}
