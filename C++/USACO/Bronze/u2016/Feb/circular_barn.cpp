#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;

int N, total=0, barn[1001];
int main() {
	IO("cbarn");
	cin >> N;
	forn(i,N) cin >> barn[i], total+=barn[i];
	int ans = 1e8;
	// cout << total << nl;
	forn(i,N) {
		int walked = 0, room[1001] = {0};
		room[i] = total;
		// cout << "i:" << i << nl;
		for(int j=0; j<N-1; j++) {
			int cur = (j+i)%N;
			int ahead = (i+j+1)%N;
			// cout << "cur:" << cur << " ahead: " << ahead << nl;
			room[ahead] += room[cur] - barn[cur]; 
			walked += room[ahead];
		}
		ans = min(walked, ans);
	}
	cout << ans << nl;
}
