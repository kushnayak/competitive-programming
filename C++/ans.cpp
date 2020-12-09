#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define f first
#define s second
#define pb push_back
using namespace std;
using pi = pair<int, int>;

int N;
pi interval[100000];

int main() {
	IO("lifeguards");
	cin >> N; 
	forn(i,N)
		cin >> interval[i].f >> interval[i].s;

	sort(interval, interval+N);

	int prev_end = -1, alone = int(1e9), total = 0;

	for (int i=0; i<N; i++) {
		pi cur = interval[i];
		if (cur.f < prev_end) {
			if (cur.s < prev_end) {
				alone = 0;
			} else {
				alone = cur.s - prev_end;
				total += cur.s - prev_end;
			}
		} else {
			alone = min(alone, cur.s - cur.f);
			total += cur.s-cur.f;
		}
		prev_end = cur.s;
	}

	cout << total - alone << nl;

	
}
