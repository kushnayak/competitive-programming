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

/*
Very cool problem
Solution:
First we can make the observation that if some money K is able to allow transmission of all cows,
then any value>K also will allow the transmission of all cows; this function is monotonic. Since
this is the case, we can just binary search on the money it will take to transmit to all cows.
For the check function we can just generate an undirected graph where 2 nodes are connected if
they are reachable with K money. Now dfs on node 0 to see if all nodes are visited.
Time complexity: O((N^2+N)(log(maxN))) -> O(N^2+N(32)) -> O(N^2+N)
*/
const int maxN=1005;
int N, x[maxN], y[maxN], total;
vector<int> adj[1005];
bool visited[maxN];

void dfs(int s){
	if(visited[s]) return;
	total++; visited[s] = true;
	for(int u: adj[s]) dfs(u);
}
// check if we can transmit to everyone with K money
bool check(int K){
	memset(visited,0,N); total=0; forn(i,N) adj[i].clear();
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			if((int)pow(x[i]-x[j],2)+pow(y[i]-y[j],2)<=K) {
				adj[i].pb(j); adj[j].pb(i);
			}
	dfs(0);
	return total == N;
}

int search(){
	int pos=0, max=INT_MAX;
	for(int a=max; a>=1; a/=2)
		while(!check(pos+a)) pos += a;
	return pos+1;
}
int main() {
	IO("moocast");
	cin >> N; forn(i,N)	cin >> x[i] >> y[i];
	cout << search() << nl;
}

