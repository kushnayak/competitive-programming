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
int N, M, color[maxN];
vector<int> adj[maxN];
bool visited[maxN], ok=true;

void dfs(int s, int cur=1){
	visited[s] = true;
	color[s] = cur;
	for(int u: adj[s]){
		if(visited[u]){
			if(color[u]==color[s]) ok = false;
		} else{
			dfs(u,!cur);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	forn(i,M){
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	for(int i=0; ok&&i<N; i++){
		if(!visited[i]) dfs(i);
	}
	if(!ok){
		cout << "IMPOSSIBLE" << nl;
	} else {
		forn(i,N)
			cout << color[i]+1 << " \n"[i==N-1];
	}
}

