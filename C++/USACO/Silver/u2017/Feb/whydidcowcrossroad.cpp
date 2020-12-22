#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
using pii = pair<int, int>;

int N, C;
multiset<int> chickens;
vector<pii> cows;

/*greedy here is that first we want to sort the cows by whichever ends earliest
this is because then we can have more future possibilities for a given chicken 
(http://darrenyao.com/usacobook/cpp.pdf#page=41)
then we want to assign the earliest starting chicken to the cow so we can give more options 
to later cows
e.g.
        -----------------------------------
 ------------
     c1  c2
choosing c1 allows us to use c2 for the second interval giving the most optimal

*/
int main() {
	IO("helpcross");
	cin >> C >> N;
	forn(i,C) {int c; cin >> c; chickens.insert(c); }
	forn(i,N) {int x,y; cin >> x >> y; cows.push_back(pii(y,x)); }
	sort(cows.begin(),cows.end());
	int ans = 0;
	for (int i=0; i<N; i++) {
		auto cow = chickens.lower_bound(cows[i].second);
		if (cow != chickens.end() && *cow <= cows[i].first) {
			ans++;
			chickens.erase(cow);
		}
	}
	cout << ans << nl;
	
}
