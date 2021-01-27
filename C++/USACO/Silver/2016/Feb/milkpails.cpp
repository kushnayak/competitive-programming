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

int X, Y, K, M, ans=INT_MAX, visited[201][201][201],total;

/*
Solution:
Floodfill on every state and take a min. Keep track of states so you don't repeat
a recursion branch. Idk what the time complexity is for this.
*/
void ff(int a, int b, int k){
	if(visited[a][b][k]||k>K){ return; }
	ans = min(ans, (int)abs(b+a-M));
	visited[a][b][k]=true;
	total++;
	// cout << "visited x:" << a << " y:" << b << " k:" << k << nl;
	ff(X,b,k+1);
	ff(a,Y,k+1);
	ff(0,b,k+1);
	ff(a,0,k+1);
	int poured1=min(X-a,b);
	int poured2=min(Y-b,a);
	ff(a+poured1,b-poured1,k+1);
	ff(a-poured2,b+poured2,k+1);
}
int main() {
	IO("pails");
	cin >> X >> Y >> K >> M;
	ff(0,0,0);
	// cout << "total states vistited:" << total << nl;
	cout << ans << nl;
}

