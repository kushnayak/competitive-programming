#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

string S, T, R;
int main() {
	IO("censor");

	cin >> S >> T;

	for (int i=0; i<S.size(); i++) {
		R += S[i];

		if (R.size()>=T.size() && R.substr(R.size()-T.size()) == T)
			R.resize(R.size()-T.size());
	}

	cout << R << nl;
	
}
