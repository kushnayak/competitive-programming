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

unordered_set<char> ans;
string s; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s; for(char c: s) ans.insert(c);
	if(sz(ans)%2==0) cout << "CHAT WITH HER!" << nl;
	else cout << "IGNORE HIM!" << nl;
}

