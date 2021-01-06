#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define x first 
#define y second
using namespace std;
using pii = pair<int,int>;

int N;
pii p[50000], xp[50000], yp[50000];

int find(pii &a) {
	forn(i,N) if(p[i]==a) return i;
	return -1;
}

long long area(int a=-1, int b=-1, int c=-1) {
	int max_x = -1, max_y = -1;
	int min_x = 40001, min_y = 40001;
	forn(i,N) {
		if (i==a||i==b||i==c)
			continue;
		max_x = max(max_x, p[i].x);
		min_x = min(min_x, p[i].x);
		max_y = max(max_y, p[i].y);
		min_y = min(min_y, p[i].y);
	}
	// cout << "max/min: " << max_x << " " << min_x << " " << max_y << " " << min_y << nl;
	return (max_x - min_x) * (max_y - min_y);
}
int main() {
	IO("reduce");
	cin >> N;
	forn(i,N) cin >> p[i].x >> p[i].y, xp[i]=p[i], yp[i]=p[i];

	sort(xp,xp+N, [](const pii &a, const pii &b) -> bool {
		return a.x < b.x;
	});
	sort(yp,yp+N, [](const pii &a, const pii &b) -> bool {
		return a.y < b.y;
	});

	long long ans = int(1e10);
	vector<pii> rm;
	for (int i=0; i<3; i++) {
		rm.push_back(xp[i]);
		rm.push_back(yp[i]);
		rm.push_back(xp[N-i-1]);
		rm.push_back(yp[N-i-1]);
	}

	// cout << "remove:" << nl;
	// for (auto u: rm) {
	// 	cout << u.x << " " << u.y << nl;
	// }
	for (int i=0; i<12; i++) 
		for (int j=i+1; j<12; j++) 
			for (int k=j+1; k<12; k++) 
				ans = min(ans, area(find(rm[i]),find(rm[j]),find(rm[k])));
			
	cout << ans << nl;
}
