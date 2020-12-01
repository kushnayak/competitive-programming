#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define endl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int b[4], a[4], p[3], enter = 0;
int main() {
	IO("promote");
	forn(i, 4)
		cin >> b[i] >> a[i], enter += a[i] - b[i];

	b[0] += enter;

	forn(i, 3) {
		int mv = b[i] - a[i];
		p[i] = mv; 
		b[i+1] += mv;
	}

	forn(i, 3)
		cout << p[i] << endl;

}
