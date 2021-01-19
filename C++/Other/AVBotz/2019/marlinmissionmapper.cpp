#include <iostream>
#include <cstdio>
#include <cmath>
#define nl '\n'

using namespace std;

struct Point {
	double x, y, z;
	double dist(Point &p) {
		return sqrt(pow(p.x-x,2)+pow(p.y-y,2)+pow(p.z-z,2));
	}
};

int N;
double ans = 0x7FFFFFFF;
Point points[10];

double compute() {
	double sum = 0;
	Point prev; 
	prev.x=0, prev.y=0, prev.z=0;
	for (int i=0; i<N; i++) {
		sum += points[i].dist(prev);
		prev = points[i];
	}
	return sum;
}
void heap(int sz) {
	if (sz==1) {
		ans = min(ans, compute());
		return;
	}
    for (int i=0; i<sz; i++) {
    	heap(sz-1);
		if (sz%2==1)
		    swap(points[0], points[sz-1]);
		else
			swap(points[i], points[sz-1]);
	}
}
void solve() {
	cin >> N;
	for(int i=0; i<N; i++) 
		cin >> points[i].x >> points[i].y >> points[i].z;	
	cout << round(compute()) << " ";
	heap(N);
	cout << round(ans) << nl;
}
int main()  {
	cin.tie(0)->sync_with_stdio(0);
	if (fopen("mission.in","r")) 
		freopen("mission.in","r",stdin), freopen("mission.out","w",stdout);
	solve();
}