#include <cstdio>
#include <iostream>
#include <cmath>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	IO("Image");

	int n;
	cin >> n;
	int channel[n][n];

	int mx = 0, mn = 0x7FFFFFFF;

	forn(i,n) {
		forn(j,n){
			cin >> channel[i][j]; 
			mx=max(mx,channel[i][j]), mn=min(mn, channel[i][j]);
			if(j!=n-1) cin.ignore(1);
		}
	}

	forn(i,n) {
		forn(j,n) {
			if (mx-mn>=10 && channel[i][j]<100)
				channel[i][j] += round(.1*(mx-mn));
			cout << channel[i][j];
			if(j!=n-1) cout<<";";
		}
		cout << nl;
	}


		
}
