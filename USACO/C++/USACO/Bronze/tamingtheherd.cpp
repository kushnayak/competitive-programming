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

int N, logg[100];

int main() {
	setIO("taming");
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> logg[i];

	if (logg[0] > 0) {
		cout << -1 << nl;
		return 0;
	}

	logg[0] = 0;

	for (int i=N-1; i>0; i--) {
		if (logg[i] > 0) {
			for (int j=i; j>=i-logg[i]; j--) {
				if (logg[j] == -1 || logg[j] == logg[i]-(i-j)){
					logg[j] = logg[i]-(i-j);
				} else {
					cout << -1 << nl;
					return 0;
				}
			}
		}
	}

	int min = 0, max = 0;

	for (int i=0; i<N; i++) {
		if (logg[i]==0) {
			min++;
			max++;
		} else if (logg[i] == -1) {
			max++;
		}

	}

	cout << min << " " << max << nl; 

}
