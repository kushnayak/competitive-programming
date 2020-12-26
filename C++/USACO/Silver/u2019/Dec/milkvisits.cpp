#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define pb push_back 

using namespace std;
const int maxN = 1e5;

int N, M;
int comp[maxN];
vector<int> adj[maxN];
char color[maxN];
string s;
int num = 1;

/*
Solution: 
https://www.stefan-pochmann.info/spots/tutorials/connected_components_and_floodfill/#:~:text=There%27s%20a%20more%20general%20problem,component%20as%20large%20as%20possible
It would be too slow to brute force dfs... something faster is needed
A key observation can be made that if a query has endpoints the same 
component, a milk preference can be acheived if the color of that component
is the same as the color the farmer wants
If 2 endpoints are not part of the same component, both color choices
NEED to be found on the path a different color must be in between the 2 endpoints,
intervening from them being part of the same component 
(can also be solved using dsu 
https://github.com/hzhuarry/Competitive-Programming/blob/master/USACO/Contest/2019-2020/Dec/Silver/milkvisits-DSU.cpp
https://discord.com/channels/516125324711297024/733495198256070766/791196889932103690)
time complexity: O(n+m)

*/
void dfs(int s) {
	if (comp[s]) return;
	comp[s] = num;
	for (auto u: adj[s])
		if (color[u]==color[s])
			dfs(u);
}
int main() {
	IO("milkvisits");
	cin >> N >> M;
	cin >> s;
	forn(i,N-1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b); adj[b].pb(a);
	}

	forn(i,N) 
		color[i] = s[i];

	forn(i,N){
		if (!comp[i]) {
			dfs(i);
			num++;
		}
	}

	// print_arr(comp, N);

	forn(i,M) {
		int a, b; char c; cin >> a >> b >> c;
		a--; b--;
		if (comp[a]==comp[b]) {
			if (color[a]==c) cout << 1;
			else cout << 0;
		} else {
			cout << 1;
		}
	}
	cout << nl;
}
