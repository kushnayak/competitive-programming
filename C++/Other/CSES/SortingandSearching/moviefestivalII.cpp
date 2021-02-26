#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).e()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define start second
#define e first

int N, K;
pii interval[(int)2e5+5];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	forn(i,N) cin >> interval[i].start >> interval[i].e;
	sort(interval,interval+N);

	multiset<int,greater<int>> ending;
	int ans=0;
	forn(i,N){
		auto it=ending.lower_bound(interval[i].start);
		if(it!=ending.end()){
			ending.erase(it);
			ending.insert(interval[i].e);
			ans++;
			continue;
		}
		if(sz(ending)<K){
			ending.insert(interval[i].e);
			ans++;
		}
	}
	cout << ans << nl;
}

