#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back 
using namespace std;

int N, c[50000*2+5];
vector<int> bessie, elsie;
int main() {
	IO("highcard");
	cin >> N;
	forn(i,N) {
		int card;
		cin >> card;
		c[card] = 1;
		elsie.pb(card);
	}
	
	for (int i=1; i<=N*2; i++)
		if (!c[i])
			bessie.pb(i);

	int ans = 0;
	for (int i=0; i<N; i++) {
		auto play = upper_bound(bessie.begin(),bessie.end(),elsie[i]);
		if (play == bessie.end()) {
			bessie.erase(bessie.begin());
		} else {
			ans++;
			bessie.erase(play);
		}
	}
	cout << ans << nl;

}

