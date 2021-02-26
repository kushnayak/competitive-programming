#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; 
	cin >> n; 
	ll l=1, r=n*n, sum=0;
	while(l<r){
		sum=0; 
		ll mid=(l+r)/2; 
		for(int i=1; i<=n; ++i)
			sum+=min(n, mid/i); 
		if(sum>=(n*n+1)/2){
			r = mid;
		} else {
			l = mid+1;
		}
	}
	cout << l << nl;
}

