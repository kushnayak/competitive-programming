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

const int maxN=2005;
const string mv="NESW";
const int dy[]={1,0,-1,0};
const int dx[]={0,1,0,-1};
int N, ans, grid[maxN][maxN], posx=1000, posy=1000; //consider origin as 1000,1000
bool fence[maxN][maxN], visited[maxN][maxN];

/*
Solution:
Observation to make is that in the grid the nubmer of doors needed to open
is the number of regions in the grid minus one. So we can just floodfill
to find the number of components or "regions" and subtract by 1. Implementation
detail: multiply length of fence by 2 so that the fence is not unit length
and instead it is an actual point that can represented on the grid. 
Time complexity: O(N^2)
*/

void ff(int r, int c){
	if(r>=maxN|| r<0 || c>=maxN || c<0){ return;}
	if(fence[r][c]) return;
	if(visited[r][c]) return;
	visited[r][c] = true;
	forn(i,4) ff(r+dy[i],c+dx[i]);
}
int main() {
	IO("gates");
	cin >> N;
	fence[posy][posx]=true;
	forn(i,N){
		char c; int d; cin >> c; 
		forn(j,4) if(mv[j]==c) d=j;
		forn(j,2){
			posy+=dy[d]; posx+=dx[d];
			fence[posy][posx]=true;
		}
	}
	
	forn(i,maxN)
		forn(j,maxN)
			if(!visited[i][j] && !fence[i][j]){
				ff(i,j); ans++;
			}
	cout << ans-1 << nl;
}	

