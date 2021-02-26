#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define pb push_back 

using namespace std;

const int maxN=1e5+5;
int N,ans;
vector<int> adj[maxN];

void dfs(int s, int from=-1){
	int total=adj[s].size(), days=0, count=1;
	if(from==-1) total++;
	while(count<total){
		days++; count*=2;
	}
	ans+=days;
	for(int u: adj[s]) if(u!=from) {ans++;dfs(u,s);};
}	
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N-1){
		int a,b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(0);
	cout << ans << nl;
}

