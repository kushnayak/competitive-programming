#include <bits/stdc++.h>
#define n first
#define r second
#define nl '\n'
using namespace std;
using pii = pair<int,int>;
const int maxN = 5005;

int N, Q, total, s, k;
vector<pii> adj[maxN];
bool visited[maxN];

void bfs(){
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty()){
		int s = q.front(); q.pop();
		for(auto u: adj[s]) {
			if(visited[u.n]||u.r<k) continue;
			visited[u.n]=true; total++;
			q.push(u.n);
		}
	}
}
int main(){
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> N >> Q;
	for(int i=0; i<N-1; i++){
		int a,b,rel; cin >> a >> b >> rel; a--; b--;
		adj[a].push_back(make_pair(b,rel));
		adj[b].push_back(make_pair(a,rel));
	}

	while(Q--){
		cin >> k >> s; s--;
		bfs();
		cout << total << nl;
		memset(visited,0,N);
		total=0;
	}
}