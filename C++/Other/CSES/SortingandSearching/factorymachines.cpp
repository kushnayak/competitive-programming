#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N, T, k[(int)2e5+5];

bool check(ll max_time){
	ll left = T;
	forn(i,N){
		left -= max_time/k[i];
		if(left<=0) return true;
	}
	return false;
}
ll search(){
	ll pos=0, mx=1e12;
	for(ll a=mx; a>=1; a/=2){
		while(!check(pos+a)) pos+=a;
	}
	return pos+1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> T;
	forn(i,N) cin >> k[i];
	sort(k,k+N);
	cout << search() << nl;
}

