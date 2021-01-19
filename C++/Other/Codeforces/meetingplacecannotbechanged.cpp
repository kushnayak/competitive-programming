// basically correct just issues with ouput precision
#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define nl '\n'
using namespace std;

const int maxN = 60005;
double N, x[maxN], v[maxN];

bool check(double t){
	double lmax = -DBL_MAX, rmin = DBL_MAX;
	forn(i,N){
		double diff = v[i]*t;
		lmax = max(lmax,x[i]-diff); rmin = min(rmin,x[i]+diff);
	}
	return (lmax<=rmin || abs(rmin-lmax) <= 0.0000001);
}

double search(){
	double pos=0, mx=2e9;
	for(double a=mx; a>=2e-6; a/=2){
		// cout << " on jump: " << a << nl;
		while(!check(pos+a)){
			pos += a;
			// cout << " going to " << pos << nl;
		}
	}
	return pos;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N; forn(i,N) cin >> x[i]; forn(i,N) cin >> v[i];
	cout << search() << nl;
}

