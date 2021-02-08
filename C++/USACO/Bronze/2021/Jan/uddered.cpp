#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sz(v) (int)(w).size()

string a,w;
int ptr,ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> w;
	while(ptr<sz(w)){ ans++; for(char c: a) if(w[ptr]==c&&ptr<sz(w)) ptr++; }
	cout << ans << nl;
}