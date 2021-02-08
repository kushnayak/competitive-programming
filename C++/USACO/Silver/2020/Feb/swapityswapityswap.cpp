#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int maxN=1e5+5;
int N, M, K;
int arr[maxN], to[maxN], comp[maxN], ind[maxN], ans[maxN];
vector<int> cycle[maxN];

int main() {
	IO("swap");
	cin >> N >> M >> K;
	forn(i,N){ arr[i]=i; }
	forn(i,M){
		int l,r; cin >> l >> r; 
		l--; r--;
		while(l<=r){
			swap(arr[l],arr[r]); 
			l++; r--;
		}
	}
	forn(i,N){
		to[arr[i]]=i;
	}
	int cur=1; 
	forn(i,N) if(!comp[i]){
		comp[i]=cur;
		cycle[cur].pb(i);
		int j=to[i];
		if(i!=j){ ind[j]=1; }
		while(i!=j){
			comp[j]=cur;
			cycle[cur].pb(j); 
			if(j!=to[j]){ ind[to[j]]=ind[j]+1; }
			j=to[j];
		}
		cur++;
	}
	forn(i,N){
		ans[cycle[comp[i]][(ind[i]+K)%sz(cycle[comp[i]])]]=i;
	}
	forn(i,N) cout << ans[i]+1 << nl;
	
}

