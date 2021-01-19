#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define nl '\n'
using namespace std;
const int maxN = 2e5;
int N,X,arr[maxN];
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> X;
	forn(i,N) cin >> arr[i];
	unordered_map<int,int> seen;
	int a=0, b=-1;
	for(;a<N; a++){
		if(arr[a]>X) continue;
		if(seen.find(X-arr[a])!=seen.end()){
			b=seen[X-arr[a]];
			break;
		}
		else{ 
			seen[arr[a]]=a; 
		}
	}
	if(b!=-1) cout << ++a << " " << ++b;
	else cout << "IMPOSSIBLE" << nl;
}