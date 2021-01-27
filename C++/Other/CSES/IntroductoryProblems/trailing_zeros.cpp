// good explanation:
// https://brilliant.org/wiki/trailing-number-of-zeros/
#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define sz(v) (int)v.size()
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll N, ans=0; cin >> N;
	for(ll i=1; i<=(ll)(log(N)/log(5)); i++) ans += N/pow(5,i);
	cout << ans << nl;
}