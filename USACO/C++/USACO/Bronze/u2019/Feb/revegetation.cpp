#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

using namespace std;

int main() {
	IO("revegetate");
	int N, M;
	vector<int> adj[100];
	int color[100] = {0};
	cin >> N >> M;
	forn(i,M) {
		int a, b;
		cin >> a >> b; a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	
	// print_arr(color, N);

	for (int i=0; i<N; i++) {
		int ok[5] = {1,1,1,1,1};
		// print_arr(ok, 5);
		for (int node: adj[i])
			if (color[node]>0) 
				ok[color[node]] = 0;

		for (int j=1; j<=4; j++) 
			if (ok[j]==1) {
				color[i] = j;
				break;
			}
		cout << color[i];
	}
	cout << nl;
		
}
