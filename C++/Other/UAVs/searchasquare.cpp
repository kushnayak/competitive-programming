#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;

int maxx, maxy, minx=INT_MAX, miny=INT_MAX;
int main() {
	IO("square");
	int x, y;
	while(cin >> x >> y){
		maxx=max(x,maxx); maxy=max(y,maxy);
		minx=min(x,minx); miny=min(y,miny);
	}
	int l=max(maxx-minx,maxy-miny);
	cout << l*l << nl;
}

