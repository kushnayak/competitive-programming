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

/*
Solution:
Simple bipartitness check, do this by coloring the graph based on same and diff neighbors.
If we find an invalid neighbor then coloring at all is impossible. 
Time complexity: O(N+M)
*/ 
const int maxN=1e5+5;
int N, M, color[maxN], cmps;
bool visited[maxN], ok=true;
vector<int> same[maxN], diff[maxN];

void dfs(int s, int cur=1){
	color[s]=cur;
	visited[s]=true;
	for(int u: same[s]){
		if(visited[u]){
			if(color[s]!=color[u]) 
				ok=false; 
		}
		else{
			dfs(u,cur); 
		}
	}
	for(int u: diff[s]){
		if(visited[u]){
			if(color[s]==color[u])
				ok=false;
		} else {
			dfs(u,!cur);
		}
	}
}
int main() {
	IO("revegetate");
	cin >> N >> M;
	forn(i,M){
		int a, b; char c; cin >> c >> a >> b; a--; b--;
		if(c=='S'){same[a].pb(b); same[b].pb(a); }
		if(c=='D'){diff[a].pb(b); diff[b].pb(a); }
	}
	for(int i=0; ok&&i<N; i++){
		if(!visited[i]){
			dfs(i); cmps++;
		}
	}
	if(!ok) { cout << 0 << nl; }
	else {
		cout << 1;
		forn(i,cmps) cout << 0;
		cout << nl;
	}
}

