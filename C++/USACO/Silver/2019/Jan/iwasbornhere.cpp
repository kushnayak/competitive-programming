#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int N;
pair<int, int> endp[100000];

// if both beginning intervals are the same (i.e. (1,5),(1,6))
// then we want (1,6) to come before (1,5) because if not, it would 
// count (1,5) and (1,6) when (1,6) is actually covering (1,5)
bool cmp(const pii &p1, const pii &p2) {
	if (p1.f == p2.f) return p2.s < p1.s;
	return p1.f < p2.f;

}
int main() {
	IO("mountains");
	cin >> N;
	forn(i,N) {
		int x, y;
		cin >> x >> y;
		endp[i] = {x-y, x+y};
	}	

	sort(endp, endp+N, cmp);
	int mx = -1;
	int ans = 0;
	for(int i=0; i<N; i++) {
		if (endp[i].s > mx) {
			ans++;
			mx = endp[i].s;
		}
	}

	cout << ans << nl;
}
