/*
O(n+m) n-nodes m-edges
O(n) comes from the time it takes to intialize the bool visited array to false for each node
O(m) is really O(2m) because each edge is considered twice (i.e. visiting child node from 
parent node and from child node still considering to visit the parent node becuase they are connected)
However this scalar constant is diregarded in the big o notation so it is just O(M)
*/
#include <iostream>
#include <vector>
using namespace std;
/*
	format: n m  next m lines edge 
	7 6
	1 2 
	1 5
	2 3
	2 4
	5 6 
	5 7
*/
int N, M;
bool vis[7];
vector<int> adj[7];

void dfs(int s) {
	visited[s] = true;
	//process
	cout << "visited " << s << '\n';
	for (auto u: adj[s])
		if(!vis[u])
			dfs(u);
}
int main() {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int from, to;
		cin >> from >> to; from--; to--;
		adj[from].push_back(to); 
		adj[to].push_back(from);
	}
	dfs(0);
}