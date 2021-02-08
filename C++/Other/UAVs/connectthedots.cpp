#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;

double dist(const pii& a, const pii& b){ return hypot(a.x-b.x,a.y-b.y); } 

int main() {
	IO("connect");

	pii cur, prev;
	cin >> prev.x >> prev.y;
	cout << setprecision(3) << fixed;
	while(cin >> cur.x >> cur.y){
		cout << dist(cur,prev) << nl;
		prev=cur;
	}
	cout << 0 << nl;
}

