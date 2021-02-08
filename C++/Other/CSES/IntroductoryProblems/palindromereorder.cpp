#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define f first
#define s second
string s; 
gp_hash_table<char,int> umap;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	for(char c: s){
		if(umap.find(c)==umap.end()) umap[c]=1;
		else umap[c]++;
	}
	int odd=0;
	char mid;
	for(auto u: umap){
		if(u.s%2==1) { odd++; mid=u.f; }
	}
	if(odd>1){ cout << "NO SOLUTION" << nl; return 0; }
	string ans="";
	for(auto u: umap){
		if(u.s%2==0)
			forn(i,u.s/2)
				ans+=u.f;
		else 
			forn(i,(u.s-1)/2)
				ans+=u.f;
	}
	string temp=ans;
	reverse(temp.begin(),temp.end());
	if(odd){ ans+=mid; }
	ans+=temp;
	cout << ans << nl;
}

