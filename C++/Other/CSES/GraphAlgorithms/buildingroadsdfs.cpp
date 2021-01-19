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
int N, M, ans[maxN];
bool visited[maxN];
vector<int> adj[maxN];

void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	for(int u: adj[s])
		dfs(u);
}

int components(){
	int cmp=0;
	forn(i,N){
		if(!visited[i]){
			ans[cmp++] = i;
			dfs(i);
		}
	}
	return cmp;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M; 
	forn(i,M){
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	int cmp = components();
	cout << cmp-1 << nl;
	forn(i,cmp-1){
		cout << ans[i]+1 << " " << ans[i+1a]+1 << nl;
	}

}

