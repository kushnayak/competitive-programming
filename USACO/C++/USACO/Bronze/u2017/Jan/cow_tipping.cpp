#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)

using namespace std;

int n, ans=0; 
char tip[10][10];

void print() {
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++) {
			cout << tip[i][j];
		}
		cout <<nl;
	}
	cout << nl;
}
//flips the rect needed to flip pos row, col
void flip(int row, int col) {
	for (int i=0; i<=row; i++) {
		for (int j=0; j<=col; j++) {
			if (tip[i][j]=='0')
				tip[i][j] = '1';
			else if (tip[i][j]=='1')
				tip[i][j] = '0';
		}
	} 
	ans++;
}
int main() {
	IO("cowtip");
	cin >> n;
	forn(i, n)
		forn(j, n)
			cin >> tip[i][j];

	// cout << nl;
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			if (tip[i][j]=='1'){
				flip(i,j);
				// cout << "flip at pos " << i << " " << j << nl;
				// print();
			}
		}
	}

	cout << ans << nl;


	
}
