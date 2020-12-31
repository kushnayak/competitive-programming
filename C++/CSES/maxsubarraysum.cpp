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
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const ll inf = LLONG_MAX;
const int maxN = 2e5+5;
ll N, dp[maxN], ans=-inf, min_prefix = 0;

/*
Approach: 
Maintain a prefix sum, variable storing the min_prefix seen (intialized to 0 as the max subarray
sum could be maximized by dp[i]-0, or the sum of the first i elements), and the answer intialized 
to negative inf. Then go through the prefix sum, taking the max of the current ans and dp[i]-min_prefix
then update min_prefix with the current prefix val.
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for1(i,N){
		int a; cin >> a;
		dp[i] += dp[i-1] + a;
	}
	
	for1(i,N){
		ans = max(ans, dp[i]-min_prefix);
		min_prefix = min(min_prefix, dp[i]);
	}
	cout << ans << nl;

}
