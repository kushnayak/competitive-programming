#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int maxN=105, col=10, dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
int N, K;
int grid[maxN][col];
bool visited[maxN][maxN];
vector<pii> visit;
int cmps;

void dbg(){
	for(int i=N-1; i>=0; i--){
		for(int j=0; j<col; j++){ cout << grid[i][j]; }
		cout << nl;
	}
}

void reset(){ forn(i,N) memset(visited[i],0,col); }
bool out_bounds(int r, int c){ return r<0||r>=N||c<0||c>=col; }

void ff(int r, int c, int color, bool rm=false){
	if(out_bounds(r,c)){ return; }
	if(visited[r][c] || grid[r][c]!=color){ return; }
	visited[r][c]=true;
	if(rm)grid[r][c]=0;
	cmps++;
	forn(i,4){ ff(r+dy[i],c+dx[i],color,rm); }
}


bool ok(){
	reset(); visit.clear(); 
	for(int i=0; i<N; i++)
		for(int j=0; j<col; j++)
			if(grid[i][j] && !visited[i][j]){
				cmps=0;
				ff(i,j,grid[i][j]);
				if(cmps>=K) visit.push_back({i,j});
			}
	reset();
	return sz(visit);
}

void move_down(int r, int c){
	r--;
	while(!out_bounds(r,c) && !grid[r][c]){
		swap(grid[r+1][c], grid[r][c]);
		r--;
	}

}
void gravity(){
	for(int j=0; j<col; j++)
		for(int i=0; i<N; i++)
			if(grid[i][j])
				move_down(i,j);
}

int main() {
	IO("mooyomooyo"); // lol
	cin >> N >> K;
	for(int i=N-1; i>=0; i--) 
		for(int j=0; j<col; j++){
			char c; cin >> c;
			grid[i][j]=c-'0';
		}

	while(ok()){
		for(auto u: visit){
			ff(u.first, u.second, grid[u.first][u.second], true);
		}
		gravity();
	}
	dbg();

}

