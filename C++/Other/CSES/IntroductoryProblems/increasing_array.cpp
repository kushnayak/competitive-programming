#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;
using ll = long long;

ll N, arr[(int)2e5+5], ans, mx;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> arr[i];
	forn(i,N){
		if(arr[i]<mx){
			ans += mx-arr[i];
		}
		mx=max(mx,arr[i]);
	}
	cout << ans << nl;
}