#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

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

const int maxN = 1e5+5;
int B, K, N, broke[maxN], dp[maxN], ans=maxN;

/*
Solution:
Maintain a prefix sum of broken street light; iterate over each K length range and find min 
prefix sum.
Time complexity: O(N)
*/
int main() {
	IO("maxcross");
	cin >> N >> K >> B;
	forn(i,B){int a; cin >> a; a--; broke[a] = 1; }
	for1(i,N){
		if(broke[i-1]) dp[i]++;
		dp[i] += dp[i-1];
	}
	// print_arr(dp,N+1);
	for(int i=1; i<=N-K+1; i++)
		ans = min(ans, dp[i+K-1]-dp[i-1]);
	cout << ans << nl;
}

