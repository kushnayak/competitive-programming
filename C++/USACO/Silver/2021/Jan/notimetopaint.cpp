#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;
using ll = long long;

const int maxN=1e5+5;
string s;
ll N, Q, prefix[maxN], suffix[maxN], last[26];

void build(ll *dp, string s){
	memset(last,-1,sizeof(last));
	for(int i=0; i<N; i++){
		dp[i+1]=dp[i];
		if(last[s[i]-'A']==-1){ 
			dp[i+1]++;
		} else{
			int l=last[s[i]-'A'];
			for(int j=0; j<s[i]-'A'; j++)
				if(last[j]>l){
					dp[i+1]++;
					break;
				}
		}
		last[s[i]-'A']=i;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q >> s;

	build(prefix,s);
	reverse(s.begin(),s.end());
	build(suffix,s);

	forn(i,Q){
		int a,b; cin >> a >> b;
		cout << prefix[a-1]+suffix[N-b] << nl;
	}
}

