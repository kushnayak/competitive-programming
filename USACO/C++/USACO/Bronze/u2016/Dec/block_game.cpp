#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

// access a to z using ascii code 
int N, alpha[123], p1[123], p2[123];
int main() {
	IO("blocks");
	// a to z ascii is 97 to 122 inclusive
	cin >> N;

	for (int i=0; i<N; i++) {
		unordered_set<char> letters;
		string s1, s2; cin >> s1 >> s2;
		for (char c: s1)
			p1[int(c)]++;
		for (char c: s2)
			p2[int(c)]++;
		for (int i=97; i<123; i++)
			alpha[i] += max(p1[i], p2[i]);
		memset(p1, 0, sizeof(p1));
		memset(p2, 0, sizeof(p2));     
	}

	for (int i=97; i<123; i++)
		cout <</* char(i) << " " << */ alpha[i] << nl;
}
