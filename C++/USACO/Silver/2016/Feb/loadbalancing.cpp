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
#define x first
#define y second

/*
Do a line sweep, fixing horizontal, sorting by x and adding if above or below 
to respective vector. Then just go through points in above and below, finding the
min x and then setting that to the xborder+1. Then move above and below pointers
if they are to the left of the xborder. Now you can count how many are in each 
quadrant using the pointers and the size of the above below vectors. )(n^2)
*/
int n, ans; 
pii coords[1005];
bool cmp(const pii &a, const pii &b){
	return a.x<b.x;
}
int main() {
	IO("balancing");
	cin >> n;
	ans=n;
	forn(i,n) cin >> coords[i].x >> coords[i].y; 
	sort(coords,coords+n, cmp);
	for(int i=0; i<n; ++i){
		vector<pii> above; 
		vector<pii> below;
		for(int j=0; j<n; j++){
			if(coords[j].y<=coords[i].y) below.pb(coords[j]);
			else above.pb(coords[j]);
		}
		int bindex = 0, aindex=0;
		while(bindex < sz(below) || aindex < sz(above)){
			int xmin = INT_MAX;
			if(bindex < sz(below)){
				xmin = min(xmin, below[bindex].x);
			}
			if(aindex < sz(above)){
				xmin = min(xmin, above[aindex].x);
			}
			while(bindex < sz(below) && below[bindex].x==xmin)
				bindex++;
			while(aindex<sz(above) && above[aindex].x==xmin)
				aindex++;
			ans = min(ans, max( max(sz(above)-aindex, aindex), max(sz(below)-bindex, bindex) ));
		}
	}
	cout << ans << nl;
}

