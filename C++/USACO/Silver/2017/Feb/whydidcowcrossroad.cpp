#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define f first
#define s second

int C, N, ans;
multiset<int> chickens;
pii cows[20005];

int main() {
	IO("helpcross");
	cin >> C >> N;
	forn(i,C){ int a; cin >> a; chickens.insert(a); }
	forn(i,N) cin >> cows[i].s >> cows[i].f;
	sort(cows,cows+N);
	forn(i,N){
		auto it=chickens.lower_bound(cows[i].s);
		if(it!=chickens.end() && *it<=cows[i].f){
			chickens.erase(it);
			ans++;
		}
	}
	cout << ans << nl;
}

