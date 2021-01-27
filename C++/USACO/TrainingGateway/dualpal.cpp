/*
ID: kushnay1
TASK: dualpal
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

int N,S;

string base_change(int num, int base){
	string res="";
	while(num!=0){
		int rem=+num%base;
		if(rem<10) res+='0'+rem;
		else res+=rem-10+'A';
		num/=base;
	}
	reverse(res.begin(),res.end());
	return res;
}


bool palindrome(int num, int base){
	string s=base_change(num,base), rev=s;
	reverse(rev.begin(),rev.end());
	return s==rev;
}

bool check(int num){
	int total=0;
	for(int i=2; i<=10; i++){
		if(palindrome(num,i))
			total++;
		if(total>=2) return true;
	}
	return false;
}

int main() {
	IO("dualpal");
	cin >> N >> S;
	int total=0, num=S+1; 
	while(true){
		if(total==N) break;
		if(check(num)){
			total++;
			cout << num << nl;
		}
		num++;
	}
}

