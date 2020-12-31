// O(n+m)
// stack is what is used by recursive calls, can replace that with an actual stack data structure
#include <iostream>
#include <vector>
#include <stack>
#define nl '\n'
using namespace std;

int N, M;
bool visited[7];
vector<int> adj[7];

void dfs(int x) {
	stack<int> stack;
	stack.push(x);

	while(!stack.empty()) {
		int s = stack.top(); stack.pop();

		if (!visited[s]) {
			visited[s] = true;
			//process 
			cout << s << nl;
		}

		for (auto u: adj[s]) {
			if (!visited[u])
				stack.push(u);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b; a--, b--;
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}
	dfs(0);
}