#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 5e4+5;
ll N, p=0, maxpos[7], minpos[7];

/*
Solution:
First thought is to use prefix sums, however using this strategy, we 
cannot iterate over all sum pairs as O(N^2) would be too slow.
However, we can acheive finding a sum divisible by 7 in linear time
by taking the sum%7. Now when we take the sum over the range [a,b]
where mod_prefix[b] == mod_prefix[a-1], we know that this sum must 
be divisible by 7 because when we do mod_prefix[b] - mod_prefix[a-1],
the mod_prefix[a-1] removes the remainder mod_prefix[b] had.
Given this we can calculate the min and max positions for all mod 
values [0,7) and take the largest difference of 2 positions
Time complexity: O(N)
*/
int main() {
	IO("div7");
	cin >> N;
	fill(minpos,minpos+7,maxN);
	fill(maxpos,maxpos+7,-1);
	for1(i,N){
		int a; cin >> a;
		p += a;
		p %= 7;
		minpos[p] = min<ll>(i, minpos[p[i]]);
		maxpos[p] = max<ll>(i, maxpos[p[i]]);
	}
	// print_arr(p,N+1);
	// print_arr(minpos,7);
	// print_arr(maxpos,7);
	int ans = 0;
	forn(i,7) if(!(minpos[i]==maxN||maxpos[i]==-1))
		ans = max<ll>(ans,maxpos[i]-minpos[i]);
	cout << ans << nl;
}
