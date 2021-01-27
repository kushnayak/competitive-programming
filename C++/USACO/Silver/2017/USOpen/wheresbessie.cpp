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

const int maxN=21, maxCol=26;
const int dy[]={1,-1,0,0}, dx[]={0,0,-1,1};
int N, ans;
int grid[maxN][maxN];
int cmps[maxCol];
bool visited[maxN][maxN], ff_visit[maxN][maxN];
int ystart, xstart, yend, xend;

/* too lazy to finish implementation
*/
void ff(int r, int c){
	if(r<ystart || r>yend || c<xstart || c>xend){ return; }
	if(ff_visit[r][c]){ return; }
	ff_visit[r][c]=true;
	forn(i,4) ff(r+dy[i],c+dx[i]);
}
void check(int y, int x, int ysz, int xsz){
	forn(i,N) memset(ff_visit[i],0,N);
	memset(cmps,0,maxCol);
	ystart=y; xstart=x; yend=y+ysz-1; xend=x+xsz-1;
	for(int i=ystart; i<=yend; i++)
		for(int j=xstart; j<=xend; j++)
			if(!ff_visit[i][j]){
				cmps[grid[i][j]]++;
				ff(i,j);
			}
	int f=0, s=0;
	forn(i,maxCol){
		if(cmps[i] && !f){ f=cmps[i];}
		else if (cmps[i] && !s){ s=cmps[i]; }
		else if (cmps[i] && f && s){ return; }
	}
	cout << "for y:" << y << " x:" << x << " ysz:" << ysz
	<< " xsz:" << xsz << " f:" << f << " s:" << s << nl;  
	if(!((f==1&&s>1)||(f==1&&s>1))){ return; }

	ans++;
	for(int i=ystart; i<=yend; i++)
		for(int j=xstart; j<=xend; j++)
			visited[i][j]=true;
	
}
int main() {
	IO("");
	cin >> N;
	forn(i,N) forn(j,N) {
		char c; cin >> c;
		grid[i][j] = (int)c;
	}
	int ysz=N, xsz=N;
	for(int i=0; i<=N-ysz; i++){
		for(int j=0; j<=N-xsz; j++){
			if(!visited[i][j] || !visited[i+ysz][j+xsz]){
				check(i,j,ysz,xsz);
			}
		}
	}
	cout << ans << nl;
}

