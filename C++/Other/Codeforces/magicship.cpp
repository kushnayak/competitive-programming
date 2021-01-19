// almost completee
#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

#define x first
#define y second
const int maxN = 2e5;
pair<ll,ll> start, dest;
int N, dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
ll px[maxN], py[maxN];
string s, mv = "UDLR";

// if we can get from start to end in K days
bool check(ll K){
	pair<ll,ll> wind = {start.x+px[N]*(K/N)+px[K%N], start.y+py[N]*(K/N)+py[K%N]};
	cout << "wind x,y: " << wind.x << " " << wind.y << nl;
	return (ll)abs(wind.y-dest.y)+abs(wind.x-dest.x)<=K;
}

ll search(){
	ll pos=0, max=1e18; 
	for(ll a=max; a>=1; a/=2){
		while(!check(pos+a)) pos += a;
	}
	return pos+1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> start.x >> start.y >> dest.x >> dest.y >> N >> s;
	for1(i,N){
		forn(j,N) if(mv[j]==s[i-1]){
			px[i] += px[i-1] + dx[j];
			py[i] += py[i-1] + dy[j];
		}
	}

	cout << search() << nl;
}

