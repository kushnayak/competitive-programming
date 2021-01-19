#include <iostream>
#include <cstdio>
#include <cmath>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin)
#define deg(a) (a)*180.0/3.141592653589793238463
#define nl '\n'
using namespace std;

double x, y, z, vx, vz, h;

int main() {
	IO("misalign");
	cin >> x >> y >> z >> vx >> vz; h = hypot(x,y);
	cout << round(x==0?90:deg(atan(y/x))) << " " 
	<< round(x==0&&y==0?90:deg(atan(z/h))) << " " 
	<< round((vx==0?0:h/vx)+(vz==0?0:z/vz)) << nl;
}
