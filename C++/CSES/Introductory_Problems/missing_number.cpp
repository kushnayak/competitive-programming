#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;

int N, found[int(2e5+5)];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N-1){
		int a; cin >> a;
		found[a] = 1;
	}
	for(int i=1; i<=N; i++) if(!found[i]) {
		cout << i << nl; break;
	}
}

