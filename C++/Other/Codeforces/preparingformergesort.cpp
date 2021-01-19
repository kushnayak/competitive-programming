#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

vector<vector<int>> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	while(N--){
		int a; cin >> a;
		int l=0, r=sz(v);
		while(l!=r){
			int mid = (l+r)/2;
			if(a>v[mid].back()) r = mid;
			else l = mid+1;
		}
		if(l==sz(v)) v.pb({a});
		else v[l].pb(a);
	}
	for(auto& u: v)
		forn(i,sz(u))
			cout << u[i] << " \n"[i==sz(u)-1];
	

}

