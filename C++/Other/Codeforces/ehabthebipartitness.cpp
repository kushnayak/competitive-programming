#include <bits/stdc++.h>

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
int N;
ll l, r; 
vector<int> adj[maxN];
bool visited[maxN];

void dfs(int s, int color=0){
	if(visited[s]) return;
	visited[s] = true;
	if(color) l++;
	else r++;
	for(int u: adj[s])
		dfs(u,!color);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N-1){
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(0);
	cout << l*r-(N-1) << nl;
}

