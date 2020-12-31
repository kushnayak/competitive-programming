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

const int maxN = 1005;
int N, Q, dp[maxN][maxN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for1(i,N){
		for1(j,N){
			char c; cin >> c;
			if(c=='*')dp[i][j]++;
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	forn(i,Q){
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << dp[c][d]+dp[a-1][b-1]-dp[c][b-1]-dp[a-1][d] << nl;
	}
}

