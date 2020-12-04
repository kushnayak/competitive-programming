#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

int N, a, b, d[100000];

int main() {
	IO("planting");

	cin >> N; 
	forn(i,N-1){
		cin >> a >> b;
		d[a-1]++, d[b-1]++;
	}
	int mx = 0;
	forn(i,N)
		mx = max(d[i], mx);
	cout << mx+1 << nl;
}
