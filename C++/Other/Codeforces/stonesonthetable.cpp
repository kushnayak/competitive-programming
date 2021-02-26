#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;

int N, ans; 
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> s;
	char prev=s[0];
	int streak=0;
	for(int i=0; i<N; i++){
		if(s[i]==prev) streak++;
		else ans+=streak-1,streak=1;
		if(s[i]==prev&&i==N-1)ans+=streak-1;
		prev=s[i];
	}
	cout << ans << nl;
}

