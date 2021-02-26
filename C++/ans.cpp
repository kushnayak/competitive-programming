#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define s first
#define e second

ll n, m; 
pii p[100005];

bool cmp(const pii &a, const pii &b){
	return a.s < b.s;
}

// check if we can place cows at least d away
bool check(ll d){
	ll used=0; 
	int i=0; 
	ll last = p[0].s-d; 
	while(i<m){
		if(p[i].s-last>d){ 
			last = p[i].s; 
			used++; 
		}
		while(p[i].s<=last+d && last+d<=p[i].e){
			last += d; 
			used++;
		}
		i++;
	}
	return used>=n; 
}

ll search(){
	ll maxn=1e18+1, pos=0; 
	for(ll a=maxn; a>=1; a/=2)
		while(check(pos+a))
			pos += a; 
	return pos; 
}
int main() {
	#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
	IO("socdist");
	cin >> n >> m; 
	forn(i,m) cin >> p[i].s >> p[i].e;
	sort(p,p+m,cmp);

	cout << search() << nl;
}

