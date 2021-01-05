#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N, M;
multiset<int,greater<int>> mset;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	forn(i,N) {int a; cin >> a; mset.insert(a);}
	forn(i,M){
		int a; cin >> a;
		auto it = mset.lower_bound(a);
		if(it==mset.end()){
			cout << -1 << nl;
		} else {
			cout << *(it) << nl;
			mset.erase(it);
		}
	}
}

