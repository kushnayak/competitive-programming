#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

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

const ll maxN = 1e5+5;
ll N, hw[maxN], dp[maxN], rm[maxN];
double res[maxN],ans;

/*
Solution:
We need to calculate a subarray sum to find the average; this can 
easily be solved with prefix sums (or suffix which i did not use).
Now is only a matter of calculating the min; we cannot query the min
for each K as this would be O(N^2) which would be too slow.
Instead we can do a suffix min scan to find for each index what the 
min up till that point would be to find the average
Time complexity:O(n)
*/
int main() {
	IO("homework");
	cin >> N;
	fill(rm,rm+maxN,100001);
	for1(i,N) cin >> hw[i];

	for1(i,N)
		dp[i] = dp[i-1] + hw[i];

	for(int i=N; i>=1; i--)
		rm[i] = min(hw[i],rm[i+1]);

	int count = 1;

	for(int k=1; k<=N-2; k++) {
		res[k] = (dp[N]-dp[k]-rm[k+1])/((N-k-1)*1.0);
		// cout << "avg for k " << k << " is " << res[k] <<nl;
		ans = max(res[k],ans);
	}
	for(int k=1; k<=N-2; k++) if(res[k]==ans) cout << k << nl;
}










