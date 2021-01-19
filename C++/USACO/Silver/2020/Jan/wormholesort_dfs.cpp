#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define n first
#define w second

/* Solution:
Binary search on the minimum weight needed to swap all cows. If all cows can be swapped
using a minimum weight of K, then it must also be possible to swap all cows with any
minimum weight value < K, making the function monotonic. To check whether some min
weight K is viable, we can observe that any permuatation of cows is possible if 
they are all in the same component. So first dfs and consider a neighboring node
part of the same component if the weight to go from a to b is >=K. Now check if
each arr[i] in the original permuation is in the same component as i meaning we 
can swap them. Since we are uniting and querying components, dsu would also be viable,
and same logic follows for that solution.
Time complexity O((N+M)logN)
*/
const int maxN = 1e5+5;
int N, M, arr[maxN];
vector<pii> adj[maxN];
bool visited[maxN];
int comp[maxN], cmp=0;

void dfs(int s, int minw){
	if(visited[s]) return;
	visited[s] = true;
	comp[s] = cmp;
	for(auto u: adj[s])
		if(u.w>=minw)
			dfs(u.n,minw);
}
// check if a min weight suffices
bool check(int minw){
	fill(comp,comp+N,-1); memset(visited,0,N);
	forn(i,N) if(!visited[i]){
		cmp++;
		dfs(i,minw);
	}
	forn(i,N){
		if(comp[i]!=comp[arr[i]]) return false;
	}
	return true;
}

int search(){
	int pos=0, max=1e9+1;
	for(int a=max; a>=1; a/=2)
		while(check(pos+a)) pos+=a;
	return pos;
}
int main() {
	IO("wormsort");
	bool ok = true;
	cin >> N >> M;
	forn(i,N){
		cin >> arr[i]; arr[i]--;
		if(arr[i]!=i) ok = false;
	}
	if(ok){
		cout << -1 << nl;
		return 0;
	}
	
	forn(i,M){
		int a, b, c; cin>> a >> b >> c; a--; b--;
		adj[a].pb({b,c}); adj[b].pb({a,c});
	}
	cout << search() << nl;
}

