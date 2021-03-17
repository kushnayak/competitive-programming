#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

string s; ll N; 

void ans(ll index){
	if(index<sz(s)){
		cout << s[index] << nl; 
		return; 
	}
	ll len=sz(s); 
	while(len*2<=index) len *= 2; 
	if(len == index) ans(len-1); 
	ans(index-len-1); 
}
int main() {
	IO("cowcode");
	cin >> s >> N; 
	ans(N-1); 
}

