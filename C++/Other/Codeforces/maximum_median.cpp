#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back
#define ub upper_bound
#define lb lower_bound

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N, K, arr[int(2e5)];
ll check(ll a){ //operations required to raise median to a 
	ll operations = 0;
	for(int i=N/2; i<N; i++)
		operations += max<ll>(0, a-arr[i]);
	return operations;
}

ll search() {
	ll pos = 0, max = 2e9;
	for(ll a=max; a>=1; a/=2) {
		while(check(pos+a)<=K) pos += a;
	}
	return pos;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	forn(i,N) cin >> arr[i];
	sort(arr,arr+N);
	cout << search() << nl;
}

