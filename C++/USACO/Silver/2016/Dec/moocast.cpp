#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

/*
Solution:
We can picture this problem as a directed graph; there is a connection between 
2 cows a to b, if the dist(a,b) ≤ power of a, meaning cow a can reach b (not necessarily vice versa, hence directed graph)
After turning this problem into a directed graph, the solution is very simple;
dfs on each cow and take the maximum visits possible for a cow 
Time complexity: O(N(N+M))

*/
int N, x[200], y[200], p[200];
vector<int> adj[200];
bool visited[200];

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u: adj[s])
		dfs(u);
}
int main() {
	IO("moocast");
	cin >> N;
	forn(i,N)
		cin >> x[i] >> y[i] >> p[i];

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i==j) continue;
			if (hypot(double(x[i]-x[j]),double(y[i]-y[j])) <= p[i]){
				adj[i].push_back(j);
			}
		}
	}

	int ans = 0;

	for (int i=0; i<N; i++) {
		int visits = 0;
		dfs(i);
		for (int j=0; j<N; j++) if (visited[j]) visits++;
		ans = max(ans, visits);
		memset(visited, 0, N);
	}

	cout << ans << nl;
	
}
