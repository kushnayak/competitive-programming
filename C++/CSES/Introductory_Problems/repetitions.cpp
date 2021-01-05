#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;
 
string s;
int ans;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	char prev = ' ';
	int streak = 1;
	for(int i=0; i<(int)s.size(); i++){
		if(s[i]==prev) streak++;
		else ans = max(ans,streak), streak=1, prev=s[i];
		if(i==(int)s.size()-1) ans = max(ans,streak);
	}
	cout << ans << nl;
}