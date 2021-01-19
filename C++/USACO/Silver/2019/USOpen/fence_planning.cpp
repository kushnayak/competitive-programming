#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

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

/*
Solution: 
Each network of cows is a component. Find the smallest perimeter of all components.
To find each component, go i through 0...N and dfs(i) and mark each node visited
as true so you don't dfs it again in the loop. 
Time complexity: O(N+M)
*/
int N, M, x[maxN], y[maxN], minx, miny, maxx, maxy, ans=INT_MAX;
vector<int> adj[maxN];
bool visited[maxN];

int perimeter() { return 2*(maxx-minx+maxy-miny); }
void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	maxx = max(maxx, x[s]); maxy = max(maxy, y[s]);
	minx = min(minx, x[s]); miny = min(miny, y[s]);
	for(auto u: adj[s]) 
		dfs(u);
}

void solve(){
	forn(i,N){
		if(!visited[i]){
			minx=1e8+1, miny=1e8+1, maxx=0, maxy=0;
			dfs(i);
			ans = min(ans, perimeter());
		}
	}
}
int main() {
	IO("fenceplan");
	cin >> N >> M;
	forn(i,N) cin >> x[i] >> y[i];
	forn(i,M){
		int a,b; cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	solve();
	cout << ans << nl;
}

