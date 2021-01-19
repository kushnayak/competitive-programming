#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N, M, grid[1001][1001], ans;
bool visited[1001][1001];

void flood(int r, int c){
	if(r<0||r>=N||c<0||c>=M) return;
	if(!grid[r][c]) return;
	if(visited[r][c]) return;
	visited[r][c]=true;
	flood(r,c+1); flood(r+1,c); flood(r-1,c); flood(r,c-1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	forn(i,N) forn(j,M){
		char c; cin >> c; grid[i][j]=(c=='.');
	}
	forn(i,N) 
		forn(j,M) 
			if(!visited[i][j]&&grid[i][j]){
				ans++;
				flood(i,j);
			}
	cout << ans << nl;
}

