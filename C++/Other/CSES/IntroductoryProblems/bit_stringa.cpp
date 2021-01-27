#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define sz(v) (int)v.size()
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll N, ans=1; cin >> N;
	forn(i,N)
		ans = (ans%mod*2%mod)%mod;
	cout << ans << nl;
}