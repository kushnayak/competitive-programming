#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
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

const int maxN = 2e5+5;
ll N, X, dp[maxN], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> X;
	for1(i,N){
		int a; cin >> a;
		dp[i] = dp[i-1]+a;
	}
	// print_arr(dp,N+1);
	multiset<int> seen;
	for(int i=0; i<=N; i++){
		ans+=seen.count(dp[i]-X);
		seen.insert(dp[i]);
	}
	cout << ans << nl;
}

