#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define q first
#define p second
#define MAX 100000
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, R, cows[MAX], rental[MAX],  store_profit[MAX], rental_profit[MAX];
// first is q second is p
pii store[MAX];

bool cmp(const pii &p1, const pii &p2) {
	if (p1.p==p2.p) return p1.q > p2.q;
	return p1.p > p2.p;
}

int main() {
	IO("rental");
	cin >> N >> M >> R;
	forn(i,N) cin >> cows[i];
	forn(i,M) cin >> store[i].q >> store[i].p;
	forn(i,R) cin >> rental[i];

	sort(cows, cows+N, greater<int>());
	sort(rental, rental+R); 
	sort(store, store+M, cmp);

	int i=0, s=0;

	while (i<N && s<M) {
		if (cows[i]>0){
			if (store[s].q > 0) {
				int used = min(cows[i], store[s].q);
				store_profit[i] += used * store[s].p;
				store[s].q -= used; 
				cows[i] -= used;
			} else {
				s++;
			}
		} else {
			i++;
		}
	}

	// print_arr(store_profit, N);

	ll ans = 0;

	int r=R-1, rp=N-1;
	while (r>=0 && rp>=0) {
		rental_profit[rp] = rental[r];
		rp--, r--;
	}

	for (int i=0; i<N; i++){
		ans += max(store_profit[i], rental_profit[i]);
	}

	cout << ans << nl;
}
