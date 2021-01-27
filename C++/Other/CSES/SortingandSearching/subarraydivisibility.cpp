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
 
const int maxN=2e5;
ll N, sum, mod[maxN], ans;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	mod[0]++;
	forn(i,N){
		ll a; cin >> a;
		sum+=a;
		mod[sum%N]++;
	}
	for(int i=0; i<N; i++){
		ans += (mod[i]*(mod[i]-1))/(2);
	}
	cout << ans << nl;
}