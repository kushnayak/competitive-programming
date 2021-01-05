#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

ll N, T, arr[(int)1e5+3], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> T; forn(i,N) cin >> arr[i];

	ll l=0, r=0, sum=0;
	for(; r<N; r++){
		sum += arr[r];
		while(sum>T && l<=r) sum-=arr[l], l++;
		ans = max(r-l+1, ans);
	}
	cout << ans << nl;
	
}

