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
#define d first
#define end second

ll N; 
pair<ll,ll> event[(int)2e5+5];
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b){ if(a.d==b.d)return a.end<b.end; return a.d<b.d;}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> event[i].d >> event[i].end;
	sort(event,event+N,cmp);
	ll at=0, ans=0;
	forn(i,N){
		at+=event[i].d;
		ans+=event[i].end-at;
	}
	cout << ans << nl;
}

