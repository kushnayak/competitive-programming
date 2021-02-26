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

const int maxN=255;
int N, B, f[maxN], s[maxN], d[maxN], ans=INT_MAX;
bool visited[maxN][maxN];

/*
Solution:
There are O(NB) states to visit (we can visit each tile N with each boot B) and if 
we try to visit all states from a given state, we would visit at max O(N+B) states
as we can visit N tiles with the current boot or change to any of the other B boots.
Therefore if we dfs, our time compelxity would be O(N^2B+B^2N) which is doable with 
constraints. To dfs, try visiting all tiles possible with current boot and trying
switching to all boots left. Also maintain a bool visited array for each state so 
we don't visit the same state twice.
*/
void dfs(int tile, int boot, int discard){
	if(visited[tile][boot]) return;
	if(tile==N-1) ans = min(ans, discard);
	visited[tile][boot]=true;
	for(int i=1; i<=d[boot]; i++){
		if(i+tile<N && s[boot]>=f[i+tile])
			dfs(i+tile,boot,discard);
	}
	while(boot<B){
		boot++;
		discard++;
		if(s[boot]>=f[tile])
			dfs(tile,boot,discard);
	}
}
int main() {
	IO("snowboots");
	cin >> N >> B;
	forn(i,N) cin >> f[i];
	forn(i,B) cin >> s[i] >> d[i];
	dfs(0,0,0);
	cout << ans << nl;
}

