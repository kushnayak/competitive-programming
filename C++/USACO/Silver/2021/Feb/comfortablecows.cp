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
#define x first
#define y second 

const int dy[]={1,0,-1,0}, dx[]={0,1,0,-1};; 
bool grid[3000][3005];
queue<pii> q; 
int N;
int placed; 
pii none; 

int neighbor(pii p){ 
	if(!grid[p.y][p.x]) return 0; 
	int cnt=0; 
	forn(i,4){
		if(grid[p.y+dy[i]][p.x+dx[i]]) 
			cnt++; 
		else
			none = {p.x+dx[i], p.y+dy[i]}; 
	}
	return cnt; 
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N; 
	for(int in=1; in<=N; ++in){
		pii p; cin >> p.x >> p.y; 
		p.x += 1000; p.y += 1000; 
		q.push(p); 

		while(!q.empty()){
			pii cur = q.front(); q.pop(); 
			if(grid[cur.y][cur.x]) continue; 
			grid[cur.y][cur.x] = true; 
			placed++; 

			// cout << "adj at: " << cur.x-1000 << " " << cur.y-1000 << ": " << neighbor(cur) << nl; 
			if(neighbor(cur) == 3){
				// cout << "pushed: " << none.x-1000 << " " << none.y-1000 << nl; 
				q.push(none); 
			}

			forn(i,4){
				// cout << "neighbor " << cur.x+dx[i]-1000 << " "  << cur.y+dy[i]-1000
				// << " adj: " << neighbor(pii{cur.x+dx[i], cur.y+dy[i]}) << nl; 
				if(neighbor(pii{cur.x+dx[i], cur.y+dy[i]}) == 3){
					// cout << "pushed: " << none.x-1000 << " " << none.y-1000 << nl; 
					q.push(none); 
				}
			}
		}
		// cout << "placed:" << placed << nl; 
		cout << placed-in << nl; 
	}
}

