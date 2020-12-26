#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;

const int maxN = 1e5 + 5;

/*
Solution:
Prefix sum each id; add 1 to prefix[id][i] if it appears at index i
To query just take prefix[id][b]-prefix[id][a-1]
Time complexity: O(N+Q)
*/
// id h:1 g:2 j:3
int N, Q, p[4][maxN], a, b;
int query(int id) {return p[id][b]-p[id][a-1];}

int main() {
	IO("bcount");
	cin >> N >> Q;
	for1(i,N) {
		int cur; cin >> cur;
		for1(j,3)
			p[j][i] = p[j][i-1];
		p[cur][i]++;
	}
	forn(i,Q) {
		cin >> a >> b;
		cout << query(1) << " " << query(2) << " " << query(3) << nl;
	}
	
}
