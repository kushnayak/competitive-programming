#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 1e5+5;

struct DSU{
	int parent[maxN], sets;
	void init(int N){forn(i,N) parent[i] = i; sets = N; }
	int find(int a) {return parent[a]==a? a : parent[a] = find(parent[a]);}
	void unite(int a, int b){
		a = find(a); b = find(b);
		if(a!=b){
			parent[b] = a;
			sets--;
		}
	}
}dsu;

int N, M;
set<int> ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M; dsu.init(N);
	forn(i,M){
		int a, b; cin >> a >> b; a--; b--;
		dsu.unite(a,b);
	}
	cout << dsu.sets - 1 << nl;
	forn(i,N){ ans.insert(dsu.find(i)); }
	for(auto it=ans.begin(); it!=prev(ans.end()); it++){
		cout << *it+1 << " " << *(next(it,1))+1 << nl;
	}

}

