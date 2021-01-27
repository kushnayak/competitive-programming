/*
ID: kushnay1
TASK: palsquare
LANG: C++                 
*/
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

int B;

string base_change(int num){
	string res="";
	while(num!=0){
		int rem=+num%B;
		if(rem<10) res+='0'+rem;
		else res+=rem-10+'A';
		num/=B;
	}
	reverse(res.begin(),res.end());
	return res;
}


bool palindrome(int num){
	string s=base_change(num), rev=s;
	reverse(rev.begin(),rev.end());
	return s==rev;
}

int main() {
	IO("palsquare");
	cin >> B;	
	for(int i=1; i<=300; i++)
		if(palindrome(i*i))
			cout << base_change(i) << " " << base_change(i*i) << nl;
}

