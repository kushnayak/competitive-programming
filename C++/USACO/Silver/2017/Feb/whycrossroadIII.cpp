#include <bits/stdc++.h>

#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define nl '\n'

using namespace std;
using pii = pair<int,int>;
#define r first
#define c second

const int maxN=105;
const int dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
int N, K, R, ans;
pii cows[maxN]; 
bool visited[maxN][maxN];

// pair hash not supported in unordered set so create 
// a custom hash by converting pair int int to string
// and using unordered_set<string>
string hsh(const pii& p){
    return to_string(p.first) + "-" + to_string(p.second);
}

unordered_set<string> bad[maxN][maxN];

void ff(int row, int col){
	if(row<0 || row>=N || col<0 || col>=N){ return; }
	if(visited[row][col]){ return; }
	visited[row][col]=true;
	forn(i,4){
		int vr=row+dy[i], vc=col+dx[i];
		if(bad[row][col].find(hsh({vr,vc}))==bad[row][col].end())
			ff(vr,vc); 
	}
}
int main() {
	IO("countcross");
	cin >> N >> K >> R;
	forn(i,R){
		pii a, b; cin >> a.r >> a.c; cin >> b.r >> b.c;
		a.r--; a.c--; b.r--; b.c--;
		bad[a.r][a.c].insert(hsh(b));
		bad[b.r][b.c].insert(hsh(a));
	}
	forn(i,K){
		cin >> cows[i].r >> cows[i].c;
		cows[i].r--; cows[i].c--;
	}
	for(int i=0; i<K; i++){
		ff(cows[i].r, cows[i].c);
		for(int j=i+1; j<K; j++){
			if(!visited[cows[j].r][cows[j].c]) ans++;
		}
		forn(k,N) memset(visited[k],0,N);
	}
	cout << ans << nl;
}

