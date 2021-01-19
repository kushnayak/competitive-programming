#include <bits/stdc++.h>
#define IO cin.tie(0)->sync_with_stdio(0)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve() {
	int N, arr[150001], ans=0;
	unordered_set<int> set;
	cin >> N;
	forn(i,N) cin >> arr[i];
	sort(arr, arr+N);
	for (int i=0; i<N; i++) {
		bool found = false;
		for (int j=-1; j<=1&&!found; j++) {
			if (arr[i]+j>0 && set.find(arr[i]+j)==set.end()){
				set.insert(arr[i]+j);
				ans++;
				found = true;
			}
		}
	}
	cout << ans << nl;
}
int main() {
	solve();
	
}
