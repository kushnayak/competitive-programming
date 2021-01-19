#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int maxN = 1e5+5;
int N, M, arr[maxN], cell[maxN], rev[maxN], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	forn(i,N){
		cin >> arr[i];
	}
	forn(i,M){
		cin >> cell[i];
		rev[M-1-i] = cell[i];
	}
	forn(i,N){
		int optimal = INT_MAX;
		auto more = lower_bound(cell,cell+M,arr[i]);
		auto less = lower_bound(rev,rev+M,arr[i],greater<int>());
		if(more!=cell+M){
			optimal = min(optimal,abs(*more-arr[i]));
		}
		if(less!=rev+M){
			optimal = min(optimal,abs(*less-arr[i]));
		}
		ans = max(ans,optimal);
	}
	cout << ans << nl;

}

