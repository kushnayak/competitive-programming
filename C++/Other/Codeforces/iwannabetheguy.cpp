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

int N, p, q; 
vector<int> x, y; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N; 
	cin >> p; forn(i,p) {int a; cin >> a; x.pb(a); } 
	cin >> q; forn(i,q) {int a; cin >> a; y.pb(a); } 

	sort(x.begin(), x.end()); 
	sort(y.begin(), y.end()); 

	int p1 = 0, p2 = 0; 
	for(int i=1; i<=N; ++i){
		if((p1>=p || x[p1]!=i) && (p2>=q || y[p2]!=i)){
			cout << "Oh, my keyboard!" << nl;
			return 0; 
		}
		while(p1<p && x[p1]<=i) p1++; 
		while(p2<q && y[p2]<=i) p2++; 
	}
	cout << "I become the guy." << nl;
}

