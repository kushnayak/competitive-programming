#include <bits/stdc++.h>

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

int n; 
ll dpx[100005], dpy[100005];
pair<ll,ll> start, fin;
string s;
const ll maxn=1e18;

bool check(ll days){
	pair<ll,ll> to=start;
	ll mvx = (days/n)*dpx[n] + dpx[days%n];
	ll mvy = (days/n)*dpy[n] + dpy[days%n];
	to.x+=mvx; 
	to.y+=mvy;
	ll taken=abs(fin.x-to.x) + abs(fin.y-to.y);
	return taken<=days;
}
ll search(){
	ll l=0, r=maxn;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(!check(mid)){
			l=mid;
		} else {
			r=mid-1;
		}
	}
	return l;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> start.x >> start.y >> fin.x >> fin.y >> n >> s;

	for(int i=1; i<=sz(s); ++i){
		char c = s[i-1];
		switch(c){
			case 'U': ++dpy[i]; break;
			case 'D': --dpy[i]; break;
			case 'L': --dpx[i]; break;
			case 'R': ++dpx[i]; break;
		}
	}
	for(int i=1; i<=n; ++i){
		dpx[i] += dpx[i-1];
		dpy[i] += dpy[i-1];
	}

	ll ans=search();
	if(ans == maxn){
		cout << -1 << nl;
		return 0;
	}
	cout << ans+1 << nl;
}

