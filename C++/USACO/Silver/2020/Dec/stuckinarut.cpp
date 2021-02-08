#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define nl '\n'
using namespace std;

/*
Solution:
Same thing as Stuck in a Rut Bronze except with dfs. We need to track which cows stop the others so we 
can first sort all the north cows by x value and east cows by y value. Now when we go through each pair,
it will be the first interaction to take place as these are the smallest x/y and could possibly affect
further interactions (i.e. N cow a stopping E cow b which would have stopped another N cow c ). We can
track these interactions by maintaining a struct of cows which shows x,y coords and if a cow is currently
moving. We also know cow a will stop cow b if it is closer to their intersection. Now we can track which
cows stop each other so let's represent cows stopping each other as a graph, if cow a stops b, then we 
can draw a directed edge from cow a to cow b. Now if cow b previously stopped cow c, then there would
already be a directed edge from cow b to cow c, and if we dfsed on cow a, it could reach b and consequently
reach c meaning we have achieved the transitive relationship the problem stated.
Time complexity: O(n^2 + nlogn)
*/

struct cow{
	int i, x, y;
	bool moving=true;
};

bool cmp_x(const cow& a, const cow& b) {if(a.x==b.x)return a.y<b.y; return a.x<b.x;}
bool cmp_y(const cow& a, const cow& b) {if(a.y==b.y)return a.x<b.x; return a.y<b.y;}

int N, total;
vector<cow> east, north;
vector<int> adj[1005];

void dfs(int s){
	for(auto u: adj[s]){
		total++;
		dfs(u);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N){
		cow cur; char c;
		cur.i=i;
		cin >> c >> cur.x >> cur.y;
		if(c=='E') east.pb(cur);
		else if(c=='N') north.pb(cur);
	}
	sort(east.begin(),east.end(),cmp_y);
	sort(north.begin(),north.end(),cmp_x);

	for(cow& a: north){
		for(cow& b: east){
			int meet_x = a.x, meet_y = b.y;
			if(a.moving && b.moving && b.x<a.x && b.y>a.y){
				if(meet_x-b.x>meet_y-a.y){ //if cow a stops cow b
					adj[a.i].pb(b.i);
					b.moving = false;
				} else if (meet_x-b.x==meet_y-a.y){ //if they are equally distant
					;
				} else { // if cow b stops a
					adj[b.i].pb(a.i);
					a.moving = false;
				}
			}
		}
	}
	
	forn(i,N){
		total = 0;
		dfs(i);
		cout << total << nl;
	}
}

