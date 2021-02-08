#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;
using ll=long long;
const int maxN=25;

ll N, weight[maxN], barn[maxN], fit[maxN], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> weight[i];
	forn(i,N) cin >> barn[i];
	sort(weight,weight+N,greater<ll>());
	sort(barn,barn+N);
	forn(i,N){
		ll fit=weight+N-lower_bound(weight,weight+N,barn[i],greater<ll>());
		if(i==0) ans=fit;
		else ans*=fit-i;
	}
	cout << ans << nl;
}

