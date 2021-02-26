/*
incomplete 
*/
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

const int maxN=25, dy[]={1,0,-1,0}, dx[]={0,1,0,-1};

struct pcl {
	int i, j, i2, j2;
};

int N;
char grid[maxN][maxN];
bool visited[maxN][maxN];
vector<pcl> found;
int ans;

void ff(int r, int c, char col, int i, int j, int i2, int j2){
	if(r<i || r>i2 || c<j || c>j2) return;
	if(visited[r][c]) return;
	if(grid[r][c]!=col) return;
	visited[r][c]=true;
	cout << "visited: " << r << " " << c << nl;
	forn(a,4){
		ff(r+dy[a],c+dx[a],col,i,j,i2,j2);
	}
}
bool ispcl(int i, int j, int i2, int j2){
	forn(p,N) forn(k,N) visited[p][k]=0;
	int region[26]={0};
	for(int r=i; r<=i2; r++)
		for(int c=j; c<=j2; c++)
			if(!visited[r][c]){
				cout << "new regoin" << nl;
				ff(r,c,grid[r][c],i,j,i2,j2);
				region[grid[r][c]-'A']++;
			}
	int used=0, total=0;
	forn(l,26) if(region[l]){
		used++; 
		total+=region[l];
	}
	if(total==3 && used==2){
		cout << "total is 3 and used is 2" << nl;
		cout << i << " " << j << nl;
		cout << i2 <<" " << j2 << nl;
		forn(l,26){ cout << char(l+65) << ":" << region[l] << " \n"[l==25]; }
		cout << nl;
	}
	return total==3 && used==2;
}

// true if i is a subset of j
bool subset(int i, int j){
	pcl a=found[i];
	pcl b=found[j];
	return b.i<=a.i && b.j<=a.j
	&& a.i2<=b.i2 && a.j2<=b.j2;
}
bool ok(int a){
	for(int i=0; i<sz(found); i++){
		if(i==a) continue;
		if(subset(a,i)) return false;
	}
	return true;
}
int main() {
	IO("where");
	cin >> N;
	forn(i,N) forn(j,N) cin >> grid[i][j];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int i2=i; i2<N; i2++)
				for(int j2=j; j2<N; j2++) 
					if(ispcl(i,j,i2,j2)){
						found.pb({i,j,i2,j2});
					}
	for(auto u: found){
		cout << "found" << nl;
		cout << u.i << " " << u.j << nl;
		cout << u.i2 << " " << u.j2 << nl;
	}
	for(int i=0; i<sz(found); i++)
		if(ok(i))
			ans++;
	cout << ans << nl;
}

