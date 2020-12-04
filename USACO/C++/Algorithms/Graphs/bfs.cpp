// O(n+m) n-nodes m-edges
#include <iostream>
#include <vector>
#include <queue>
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

// can also maintain distance using an array and say distance[x]=0 distance[u] = distance[s]+1 each layer 1 away 
int N, M;
bool visited[7];
vector<int> adj[7];
queue<int> q;

void bfs(int x) {
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		int s = q.front(); q.pop();
		// process 
		cout << "visited " << s << '\n';
		for (auto u: adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}

	}
}

int main() {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int from, to;
		cin >> from >> to; from--; to--;
		adj[from].push_back(to); 
		adj[to].push_back(from);
	}
	bfs(0);
}
