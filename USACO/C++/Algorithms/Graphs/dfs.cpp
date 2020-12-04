// O(n+m) n-nodes m-edges
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
bool visited[7];
vector<int> adj[7];

void dfs(int s) {
	if (visited[s]) return; // reached max depth
	visited[s] = true;
	//process
	cout << "visited " << s << '\n';
	for (auto u: adj[s])
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