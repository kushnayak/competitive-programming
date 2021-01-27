#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long N; cin >> N;
	while(N!=1){
		cout << N << ' ';
		if(N%2==0)
			N /= 2;
		else 
			N = N*3 +1;
	}	
	cout << 1 << nl;
}

