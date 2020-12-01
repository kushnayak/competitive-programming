#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

int N;
string a, b;

void flip(int from, int to) {
	for (int i=from; i<=to; i++) {
		if (b[i]=='G')
			b[i] = 'H';
		else if (b[i] == 'H')
			b[i] = 'G';
	}
}
int main() {
	IO("breedflip");
	cin >> N >> a >> b;

	int swaps = 0;
	
	// flip(0,0);
	// cout << a << nl << b << nl;
	// flip(2,3);
	// cout << a << nl << b << nl;
	// cout << "a == b? " << (a==b) << nl;
	while (a != b) {
		int from  = -1, to = -1;
		for (int i=0; i<N; i++) {
			if (a[i] != b[i] && from < 0)
				from = i, to = i;
			else if (a[i] != b[i] && from >= 0)
				to = i;
			else if (a[i] == b[i] && from >= 0 && to >= from)
				break;
		}
		// cout << "from " << from << " to " << to << nl;
		flip(from, to);
		swaps++;
	}

	cout << swaps << nl;
}
