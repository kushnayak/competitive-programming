#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

int N,  c[100], s[100];
int main() {
	IO("outofplace");

	cin >> N;
	forn(i, N)
		cin >> c[i];

	copy_n(c, N, s);
	sort(s, s+N);
	int ans = 0;

	forn(i, N) {
		if (c[i] != s[i])
			ans++;
	}

	cout << ans-1 << nl;

	
}
