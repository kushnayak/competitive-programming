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

ll N, K, arr[(int)2e5];

ll to(ll from, ll max){
	ll sum=0, i=from; 
	while(i<N){
		sum += arr[i];
		if(sum>max){
			return i;
		}
		i++;
	}
	return i;
}
bool check(ll min){
	ll sub = 0, i=0;
	while(i<N){
		if(arr[i]>min) return false;
		i = to(i,min);
		sub++;
	}
	// cout << "sub  " << sub << nl;
	return sub<=K;
}

ll search(){
	ll max=9e18, pos=0; 
	for(ll a=max; a>=1; a/=2){
		while(!check(pos+a)) pos+=a;
	}
	return pos+1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K; forn(i,N) cin >> arr[i];
	cout << search() << nl;
}

