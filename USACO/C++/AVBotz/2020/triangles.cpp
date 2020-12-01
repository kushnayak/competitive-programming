#include <cstdio>
#include <iostream>
#include <cmath>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int n, x[100], y[100];
int main() {
	IO("perimeter");

	char ignore;
	cin >> n;
	forn(i,n)
		cin >> x[i] >> ignore >>  y[i];

	double sum = 0; 
	forn(i,n) {
		forn(j,n){
			if (i==j) continue;
			forn(k,n) {
				if (k==j||k==i) continue;
				if (x[i]==x[j]&&y[i]==y[k]){
					sum += abs(y[i]-y[j]) + abs(x[i]-x[k]) + hypot(x[i]-x[k],y[i]-y[j]);
				}
			}
		}
	}
	
	cout << round(sum) << nl;
	
}
