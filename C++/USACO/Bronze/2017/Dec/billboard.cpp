#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define endl '\n'

using namespace std;

int intersecting(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (min(x2,x4)-max(x1,x3) < 0 || min(y2,y4)-max(y1,y3) < 0)
		return (x2-x1) * (y2-y1);
	return (x2-x1) * (y2-y1) - ((min(x2,x4)-max(x1,x3)) * (min(y2,y4)-max(y1,y3))) ;
}
int main() {
	IO("billboard");
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6; 

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

	cout << intersecting(x1, y1, x2, y2, x5, y5, x6, y6) + intersecting(x3, y3, x4, y4, x5, y5, x6, y6) << endl;
}
