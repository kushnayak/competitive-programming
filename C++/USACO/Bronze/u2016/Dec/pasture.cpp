#include <bits/stdc++.h>
#define nl '\n'

using namespace std;


void setIO(string name) { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((name+".in").c_str(), "r", stdin); 
  freopen((name+".out").c_str(), "w", stdout);
}


int main() {
	#ifdef KUSH_LOCAL
		;
	#else 
		setIO("square");
	#endif

	int x1, y1, x2, y2, x3, y3, x4, y4;

	cin>> x1>> y1>> x2 >> y2>> x3>> y3>> x4>> y4;

	int xmin = min(min(x1,x2), min(x3, x4));
	int xmax = max(max(x1,x2), max(x3, x4));
	int ymin = min(min(y1,y2), min(y3, y4));;
	int ymax = max(max(y1,y2), max(y3, y4));

	cout << max(xmax - xmin, ymax - ymin) * max(xmax - xmin, ymax - ymin) << nl;
}
