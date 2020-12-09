#include <bits/stdc++.h>
#define FOR(i, b) for (int i=0; i<b; i++)
#define nl '\n'
using namespace std;


void setIO(string name = "") { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if(name.size()){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
  }
}

int X, Y, M;

int main() {
	setIO("pails");

	cin >> X >> Y >> M;

	int ans = 0;

	if (M%X == 0 || M%Y == 0) {
		ans = M;
	} else {
		for (int i=0; i<=M/X; i++) {
			for (int j=0; j<=M/Y; j++) {
				if (i * X + j * Y <= M)
					ans = max(ans, i * X + j * Y);
			}
		}
	}

	cout << ans << nl;
}
