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
Greedy+Binary Search. We know this function is montonic; if we are able to separate all cows with a 
minimum distance of D, we can seperate all cows with a distance d<D (becuase then there wil be 
even more space to put cows). Now we just have to check of a value D, how many cows we can fit, 
and we can do this first by sorting the intervals, then greedily by putting a cow at each 
last pos + D in a interval and if that does not work move on to next interval.
Time complexity: O((N+M)log10^18)
*/
const int maxN = 1e5 + 5;
int N, M;
pair<ll,ll> interval[maxN];

bool possible(ll D) {
	ll used = 0;
	ll last = -1e18;
	for(int i=0; i<M; i++) {
		pair<ll,ll>& cur = interval[i];
		while(max(last+D,cur.f)<=cur.s) {
			used++;
			last = max(last+D,cur.f);
			if(used>=N) break;
		}
	}
	return used>=N;
}

ll search() {
	ll pos = 1, mx = 1e18+1;
	for(ll a=mx; a>=1; a/=2)
		while(possible(pos+a)) pos+=a;
	return pos;
}
int main() {
	IO("socdist");
	cin >> N >> M;
	forn(i,M) cin >> interval[i].f >> interval[i].s;
	sort(interval,interval+M);
	cout << search() << nl;
}

