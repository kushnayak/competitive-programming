#include <bits/stdc++.h>
#define IO cin.tie(0)->sync_with_stdio(0)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve() {
	int N, arr[100001];
	cin >> N;
	forn(i,N) cin >> arr[i];
	sort(arr, arr+N);
	int i=N/2, c=0;
	bool left = false;
	string ans="";
	while (0<=i && i<N) {
		if ((N%2==1 && i==N-1)||(N%2==0 && i==0)) cout << arr[i] << nl;
		else cout << arr[i] << " ";
		left = left==false;
		c++; 
		(left) ? i += -c : i+= c;
	}
}
int main() {
	IO;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}
