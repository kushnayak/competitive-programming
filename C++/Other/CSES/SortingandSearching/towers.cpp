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

int N, arr[(int)2e5+5];
vector<vector<int>> towers;

int find(int x){
	int l=0, r=sz(towers);
	while(l!=r){
		int mid=(l+r)/2;
		if(x>=towers[mid].back()){
			l=mid+1;
		} else{
			r=mid;
		}
	}
	return l;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> arr[i];
	forn(i,N){
		int place=find(arr[i]);
		if(place==sz(towers)) towers.pb({arr[i]});
		else towers[place].pb(arr[i]);
	}
	cout << sz(towers) << nl;
}

