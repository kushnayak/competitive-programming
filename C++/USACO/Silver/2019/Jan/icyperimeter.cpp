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

/*
Solution:
Basically floodfill. Problem is amibiguous, they never tell you how to calculate perimeter 
in the problem but it is going through each cell in a component and taking sum of all out 
of bounds or '.' cells adjacent to it. Also my code works with the test data they gave but 
somehow i get only 2 cases correct??
*/
const int maxN=1005;
int N, curp, cura, ansp, ansa; 
char grid[maxN][maxN];
bool visited[maxN][maxN];

void ff(int r, int c){
	if(visited[r][c]){ return; }
	if(r<0 || r>=N || c<0 || c>=N){ curp++; return; }
	if(grid[r][c]=='.') { curp++; return; }
	cura++;
	visited[r][c]=true;
	ff(r+1,c); ff(r-1,c); ff(r,c+1); ff(r,c-1);
}
int main() {
	IO("perimeter");
	cin >> N;
	forn(i,N) forn(j,N) cin >> grid[i][j];
	forn(i,N){
		forn(j,N){
			if(!visited[i][j]){
				ff(i,j);
				if((cura>ansa) || (cura==ansa && curp<ansp)){
					ansa=cura; ansp=curp;
				}
				curp=0; cura=0;
			}
		}
	}
	cout << ansa << " " << ansp << nl;
}

