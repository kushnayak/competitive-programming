#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 5005;
ll N, X, arr[maxN], org[maxN];
bool found=false;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> X; forn(i,N) cin >> arr[i], org[i]=arr[i];
	if(N<3){
		cout << "IMPOSSIBLE" << nl;
		return 0;
	}
	sort(arr,arr+N);
	ll l, r, a=1;
	for(; a<N-1; a++){
		l=0; r=N-1;
		while(l<r){
			if(l==a) {l++; continue;}
			if(r==a) {r--; continue;}
			ll sum = arr[l]+arr[r]+arr[a];
			if(sum==X){found=true; break;}
			else if(sum<X){l++;}
			else {r--;}
		}
		if(found) break;
	}
	if(found){
		forn(i,N) if(org[i]==arr[a]) {a=i; break;}
		forn(i,N) if(org[i]==arr[l] && i!=a) {l=i; break;}
		forn(i,N) if(org[i]==arr[r] && i!=a && i!=l) {r=i; break;}
		cout << a+1 << " " << l+1 << " " << r+1 << nl;
	} else{
		cout << "IMPOSSIBLE" << nl;
	}
}

