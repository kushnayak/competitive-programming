#include <bits/stdc++.h>
#define IO cin.tie(0)->sync_with_stdio(0)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;
using pi = pair<int, int>;


int N;
vector<pi> arr;

int main() {
	IO;

	cin >> N;
	forn(i,N){
		int l, r;
		cin >> l >> r;
		arr.pb(mp(l, 1));
		arr.pb(mp(r,-1));
	}

	sort(arr.begin(), arr.end());

	int ans = 0, sum = 0;
	for(auto i: arr) {
		sum += i.s;
		ans = max(ans, sum);
	}
	cout << ans << nl;
	
}
