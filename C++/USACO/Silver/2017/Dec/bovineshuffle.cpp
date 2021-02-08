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

const int maxN=100005;
int N,ans;
int to[maxN], parent[maxN];

/*
Solution:
Start ans=N. Any nodes with 0 incoming edges will decrement ans because they will be empty.
Process all nodes that nodes with 0 incoming edges direct to in a q, they must have > 1
incoming edges to be vacant because the 0 parent to it will decrement the number of vacant
incoming edges by 1. When decrementing the parent of to[i] == 0 then to[to[i]] also needs 
to be processed.
Time complexity: O(N)
*/
int main() {
	IO("shuffle");
	cin >> N;
	forn(i,N){
		int a; cin >> a; a--;
		to[i]=a;
		parent[to[i]]++;
	}
	ans=N;
	queue<int> q;
	forn(i,N){
		if(parent[i]==0){
			ans--;
			q.push(to[i]);
		}
	}
	while(!q.empty()){
		int a=q.front(); q.pop();
		if(--parent[a]==0){
			ans--;
			q.push(to[a]);
		}
	}
	cout << ans << nl;
}

