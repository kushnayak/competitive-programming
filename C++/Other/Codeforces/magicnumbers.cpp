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

string s; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s; 
	int N=sz(s); 
	for(int i=0; i<N; ++i){
		if(s[i]=='1'){
			if(i+1<N && s[i+1]=='4'){
				int add = 1; 
				if(i+2<N && s[i+2]=='4'){
					add++; 
				}
				i += add; 
			} 
		} else {
			cout << "NO" << nl; 
			return 0; 
		}
	}
	cout << "YES" << nl; 
}

