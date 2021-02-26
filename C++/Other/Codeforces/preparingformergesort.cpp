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

int n, arr[200005];
vector<vector<int>> sorted;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n; 
	forn(i,n) cin >> arr[i];
	forn(i,n){
		int l=0, r=sz(sorted);
		while(l<r){
			int mid=(l+r)/2;
			if(arr[i]<sorted[mid].back()){
				l=mid+1; 
			} else {
				r=mid;
			}
		}
		l==sz(sorted) ? sorted.pb({arr[i]}) : sorted[l].pb(arr[i]);
	}
	for(auto u: sorted)
		for(int i: u)
			cout << i << " \n"[i==u[sz(u)-1]];
}

