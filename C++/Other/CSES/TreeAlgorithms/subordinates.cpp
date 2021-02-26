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

const int maxN=2e5+5;
int N;
vector<int> adj[maxN];
int children[maxN];

void dfs(int s, int p=-1){
	children[s]=1;
	for(auto u: adj[s]){
		if(u==p) continue;
		dfs(u,s);
		children[s]+=children[u];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for(int i=1; i<N; i++){
		int a; cin >> a; a--; 
		adj[i].pb(a);
		adj[a].pb(i);
	}
	dfs(0);
	forn(i,N) cout << --children[i] << " \n"[i==N-1];
}

