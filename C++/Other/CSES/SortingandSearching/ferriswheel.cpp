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

int N, K, p[(int)2e5+3], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	forn(i,N) cin >> p[i];
	sort(p,p+N);
	int l=0, r=N-1;
	while(l<=r){
		int sum=p[l]+p[r];
		if(l==r){ ans++; break; }
		if(sum<=K){
			ans++; l++; r--;
		} else{
			ans++; r--;
		}
	}
	cout << ans << nl;
}

