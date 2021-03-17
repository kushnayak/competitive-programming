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

string binary(int a){
	string ret=""; 
	for(int i=30; i>=0; --i){
		if(a&(1<<i))
			ret.pb('1'); 
		else 
			ret.pb('0'); 
	}
	return ret; 

}

int main() {
	int a = 0b101010; 
	cout << a << nl; 
	cout << binary(17) << nl; 
	cout << (17 << 2)+1 << nl; 
}

