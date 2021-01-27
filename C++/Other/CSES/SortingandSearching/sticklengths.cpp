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

ll N, arr[(int)2e5+5], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N; forn(i,N) cin >> arr[i];
	sort(arr,arr+N); 
	ll median=arr[N/2];
	forn(i,N){
		ans += abs(median-arr[i]);
	}
	cout << ans << nl;
}

