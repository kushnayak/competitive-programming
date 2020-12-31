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

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 1001;
int N, K, dp[maxN][maxN], ans;

/*
Solution:
We can use 2d prefix sums to calculate how much paint is applied at the given 
moment
Time complexity: O(N^2)
*/
int main() {
	IO("paintbarn");
	cin >> N >> K;
	while(N--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		dp[a][b]++; dp[c][d]++;
		dp[a][d]--; dp[c][b]--;
	}
	for(int i=0; i<maxN; i++) {
		for(int j=0; j<maxN; j++){
			if(i) dp[i][j] += dp[i-1][j];
			if(j) dp[i][j] += dp[i][j-1];
			if(i&&j) dp[i][j] -= dp[i-1][j-1];
			if(dp[i][j]==K) ans ++;
		}
	}	
	cout << ans << nl;
}

