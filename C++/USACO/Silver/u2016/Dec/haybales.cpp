#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

int N, Q, bales[100000];

int main() {
	IO("haybales");
	cin >> N >> Q;
	forn(i,N) 
		cin >> bales[i];

	sort(bales, bales+N);
	for (int i=0; i<Q; i++) {
		int a, b; cin >> a >> b;
		cout << upper_bound(bales, bales+N, b) - lower_bound(bales, bales+N, a) << nl;
	}
	
}
