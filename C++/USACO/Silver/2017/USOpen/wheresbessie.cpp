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

const int dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
struct pcl {
	int r1, c1, r2, c2; 
}cur; 

int N; 
char grid[21][21]; 
bool visited[21][21]; 
int comp[26]; 
vector<pcl> found; 

void ff(int i, int j, char color){
	if(i<cur.r1 || i>cur.r2 || j<cur.c1 || j>cur.c2) return; 
	if(visited[i][j] || grid[i][j]!=color) return; 
	visited[i][j]=true; 
	for(int d=0; d<4; ++d) ff(i+dy[d], j+dx[d], color); 
}
bool is_pcl(pcl p){
	memset(comp, 0, sizeof(comp[0])*26); 
	forn(r,N) memset(visited[r], 0, N); 
	cur = p; 
	for(int i=cur.r1; i<=cur.r2; ++i)
		for(int j=cur.c1; j<=cur.c2; ++j)
			if(!visited[i][j]){
				++comp[grid[i][j]-'A']; 
				ff(i, j, grid[i][j]); 
			}
	int total=0; 
	bool one=false, multiple=false; 
	forn(i,26){
		if(comp[i]){
			total++; 
			if(comp[i]==1) one=true; 
			if(comp[i]>1) multiple=true; 
		}
	}
	return one && multiple && total==2; 
}

int ans;

bool not_sub(int at){
	for(int i=0; i<sz(found); ++i){
		if(i==at) continue;

		if(
		found[i].r1 <= found[at].r1
		&& found[at].r2 <= found[i].r2
		&& found[i].c1 <= found[at].c1
		&& found[at].c2 <= found[i].c2
		)
			return false; 
	}
	return true; 
}
int main() {
	IO("where");
	cin >> N; 
	forn(i,N) forn(j,N) cin >> grid[i][j]; 
	for(int i1=0; i1<N; ++i1)
		for(int j1=0; j1<N; ++j1)
			for(int i2=i1; i2<N; ++i2)
				for(int j2=j1; j2<N; ++j2){
					pcl p = {i1,j1,i2,j2}; 
					if(is_pcl(p)){
						found.pb(p); 
						// cout << "pcl found:" << nl; 
						// cout << "from " << i1 << " " << j1 << nl; 
						// cout << "to " << i2 << " " << j2 << nl << nl; 
					}
				}
	for(int i=0; i<sz(found); ++i)
		if(not_sub(i))
			++ans; 
	cout << ans << nl; 
}

