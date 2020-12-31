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

const int maxN = 1e6+5;
int N, K, dp[maxN];

/*
Solution:
For a range [a,b] where stacks are placed can put down a stack at position a 
and remove a stack at position b+1. We repeat this process for all ranges, 
then compute the prefix sum of each position using the stacks we placed and 
removed. After that we sort and print the median. 
Time complexity: O(n+nlogn)

For a similar approach of "placing" of stack then performing a prefix sum, 
to see how many stacks are present check out:
http://www.usaco.org/index.php?page=viewproblem2&cpid=919
*/
int main() {
	IO("stacking");
	cin >> N >> K;
	forn(i,K) {int a, b; cin >> a >> b; dp[a]++; dp[b+1]--;}
	for1(i,N){
		dp[i] += dp[i-1];
	}
	sort(dp+1,dp+N+1);
	cout << dp[N/2] << nl;
}

