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

/*
Solution:
We have to compute the maximum prefix + suffix combination of wins using
2 of H,P,or S. This can be done easily in linear time by maintaining 
a preifx sum and taking max values from 9 queries from 1≤i≤N of each prefix/suffix
Time complexity: O(N)
*/

const int maxN = 1e5+5;
ll N, dp[4][maxN], ans; // s is 1 p is 2 h is 3
int s;
//returns a query of total wins from [1,s]of a[] + (s,N] of b[]
ll query(ll a[], ll b[]) {return a[s] + b[N] - b[s-1];}
int main() {
	IO("hps");
	cin >> N;
	for1(i,N) {
		char c; cin >> c; int pos;
		if(c=='P') pos = 1;
		if(c=='H') pos = 2;
		if(c=='S') pos = 3;
		for1(j,3) dp[j][i] = dp[j][i-1];
		dp[pos][i]++;
	}
	for(int i=0; i<=N; i++) {
		s = i;
		for1(j,3) for1(k,3) if(j!=k)
				ans = max(ans, query(dp[j],dp[k]));
	}
	cout << ans << nl;
}

