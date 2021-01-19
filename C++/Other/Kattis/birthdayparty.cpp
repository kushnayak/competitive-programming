// simulate this is correct but idk why this is segmentation fault 11
#include <bits/stdc++.h>

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
using ll = long long;

const int maxN = 101;
struct edge{ int a, b; };
edge rm;
bool visited[maxN];
vector<int> adj[maxN];
int P, C, total;

void dfs(int s){
	if(visited[s]) return;
	total++;
	for(auto u: adj[s]) 
		if(!((u==rm.a&&s==rm.b)||(u==rm.b&&s==rm.a)))
			dfs(u);
}
bool solve(){
	forn(i,P) adj[i].clear();
	vector<edge> edges;
	forn(i,C){
		int a, b; cin >> a >> b; edge e{a,b};
		adj[a].pb(b); adj[b].pb(a);
		edges.pb(e);
	}
	for(edge u: edges){
		rm = u;
		memset(visited, 0, P); 
		total = 0;
		forn(i,P) if(!(i==rm.a || i==rm.b)) dfs(i);
		if(total<P) return false;
	}
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	while(cin >> P >> C, P||C) {
		if (solve()) cout << "No" << nl;
		else cout << "Yes" << nl;
	}
	
}

