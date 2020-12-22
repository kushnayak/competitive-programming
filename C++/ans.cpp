#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int N, M;
vector<int> adj[3000];
bool visited[3000];
bool open[3000];

/* Solution:
   We can naively brute-force dfs this problem by closing a farm, 
   then dfs-ing an open farm and checking if we visit the same number
   of farms as there are open 
   time complexity: O(N*(N+M))

*/

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u: adj[s])
		if (open[u])
			dfs(u);
}

void visit() {
	int visits = 0, start = 0, total = 0;
	forn(i,N) 
		if (open[i]) total++, start = i;
	dfs(start);
	for (int i=0; i<N; i++)
		if(visited[i]) visits++;
	//cout << "start at: "<< start <<" total open: " << total << " visited: " << visits << nl;
	memset(visited, 0, N);
	if (visits == total)
		cout << "YES" << nl;
	else 
		cout << "NO" << nl;
}

void erase(int s){
	for (auto u: adj[s]){
		adj[u].erase(find(adj[u].begin(),adj[u].end(),s));
	}
	adj[s].clear();
}
int main() {
	IO("closing");
	cin >> N >> M;
	forn(i,M) {
		int a, b;
		cin >> a >> b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	for(int i=0; i<N; i++)
		open[i] = true;

	visit();

	for (int i=0; i<N-1; i++) {
		int closed; 
		cin >> closed;
		open[--closed] = false;
		visit();
	}
}
