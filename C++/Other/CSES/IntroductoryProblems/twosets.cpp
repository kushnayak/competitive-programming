#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define pb push_back
#define sz(v) (int)(v).size()
using namespace std;


int main() {
	/*
	First N numbers; sum is N/2(N+1) so we need to divide each sum
	into N(N+1)/4. If this halved sum % N == 0 then add N then keep adding
	1 ... N-1  if sum % N+1 == 0 then just repeat 2 pointer for 1...N
	l--> <--r
	Add remaining numbers to second set
	*/
	#define int long long
	int N;
	vector<int> f, s;
	cin >> N;
	if(!(N*(N+1)%4==0)){
		cout << "NO" << nl;
		return 0;
	}
	int sum = N*(N+1)/4;
	int total=0, l=1, r=N;
	if(sum%N==0){
		total += N;
		f.pb(N);
		r=N-1;
	}
	while(total!=sum){
		total += l+r;
		f.pb(l); f.pb(r);
		l++; r--;
	}
	while(l<=r){
		s.pb(l);
		l++;
	}
	cout << "YES" << nl;
	cout << sz(f) << nl;
	for(int i=0; i<sz(f); i++) cout << f[i] << " \n"[i==sz(f)-1];
	cout << sz(s) << nl;
	for(int i=0; i<sz(s); i++) cout << s[i] << " \n"[i==sz(s)-1];
}

