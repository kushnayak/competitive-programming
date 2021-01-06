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
Prefix sum each id; to find num of ids in a range then 
take (prefix[b]-prefix[a-1])/id
Time complexity: O(N+Q)
*/
// id h:1 g:2 j:3
int N, Q, line[maxN], h[maxN], g[maxN], j[maxN], a, b;

int query(int id, int prefix[]) {
	int ret = (prefix[b]-prefix[a-1])/id;
	return max(0, ret);
}
int main() {
	IO("bcount");
	cin >> N >> Q;
	for1(i,N) {
		int a; cin >> a;
		h[i] = h[i-1];
		g[i] = g[i-1];
		j[i] = j[i-1];
		if(a==1) h[i] += 1;
		else if(a==2) g[i] += 2;
		else j[i] += 3;
	}
	// cout << "H prefix: " << nl;
	// print_arr(h,N+1);
	// cout << "G prefix: " << nl;
	// print_arr(g,N+1);
	// cout << "J prefix: " << nl;
	// print_arr(j,N+1);
	forn(i,Q) {
		cin >> a >> b;
		cout << query(1,h) << " " << query(2,g) << " "
		<< query(3,j) << nl;
	}
	
}
