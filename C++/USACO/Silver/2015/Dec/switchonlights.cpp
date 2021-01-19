#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ll = long long;

/*
Solution: 
First turn on all switches from the current square and then if 
there is a visited on neighbor adjacent to a square that we turned
on then floodfill that square too. After that floodfill all squares
adjacent to the current square. Count the number of lights that was turned
on.
Time complexity: O(N^2)
*/
const int maxN = 105;
int N, M, ans; 
vector<pii> light[maxN][maxN];
bool visited[maxN][maxN], on[maxN][maxN];

bool is_on(int r, int c){ 
	if(r<0||r>N||c<0||c>N){ return false; }
	return on[r][c] && visited[r][c];
} 
bool reach(int r, int c){
	return is_on(r+1,c) || is_on(r,c+1) || is_on(r-1,c) || is_on(r,c-1);
}
 
void ff(int r, int c){
	if(r<0||r>N||c<0||c>N){ return; }
	if(visited[r][c]){ return; }
	if(!on[r][c]){ return; }
	visited[r][c]=true;
	for(auto u: light[r][c]){
		on[u.f][u.s]=true;
	}
	for(auto u: light[r][c]) if(reach(u.f,u.s)) ff(u.f,u.s);
	ff(r+1,c); ff(r,c+1); ff(r-1,c); ff(r,c-1);
}


int main() {
	IO("lightson");
	cin >> N >> M;
	forn(i,M){
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		light[a][b].pb({c,d});
	}
	on[0][0]=true;
	ff(0,0);
	forn(i,N)
		forn(j,N)
			if(on[i][j]) ans++;
	
	cout << ans << nl;
}

