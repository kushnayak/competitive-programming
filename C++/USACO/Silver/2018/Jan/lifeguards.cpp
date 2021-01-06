#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
using namespace std;

/*
Solution:
We cannot naively remove each lifeguard and check time ... too slow
Instead we can sort by time and check how much time each lifeguard spends
alone and how much total time is covered by the lifeguards, and subtract
min time spent alone from total to get our answer 
To find time spent alone we can plot each start and end point (from sorted order)
in a set; if there is single person working then subtract time from last time
from the time we are currently putting in (whether that be that same cow's endpoint
or another cow's start)

Time complexity: O(nlogn)
*/
const int maxN = 1e5;
struct point {
	int time, index;
};
bool cmp(const point& a, const point& b) {
	return a.time < b.time;
}

int N, alone[maxN];
point lg[maxN*2];
set<int> work; 

int main() {
	IO("lifeguards");
	cin >> N;
	forn(i,N) {
		int a, b; cin >> a >> b;
		lg[2*i] = point{a,i};
		lg[2*i+1] = point{b,i};
	}
	// cout << "no sort" << nl;

	// forn(i,N*2){
	// 	cout << "point "<< i << "time,ind " << lg[i].time << " " << lg[i].index<<nl;
	// }
	sort(lg,lg+2*N,cmp);
	// cout << nl << "after sort" << nl;
	// forn(i,N*2){
	// 	cout << "point "<< i << "time,ind " << lg[i].time << " " << lg[i].index<<nl;
	// }
	int last = 0, total = 0;
	for (int i=0; i<N*2; i++) {
		point cur = lg[i];
		if (work.size()==1){
			alone[*work.begin()] += cur.time - last;
		} 
		if (!work.empty()) {
			total += cur.time - last;
		}
		if (work.find(cur.index)!=work.end()) {
			work.erase(work.find(cur.index));
		} else {
			work.insert(cur.index);
		}
		last = cur.time;
	}
	// print_arr(alone,N);
	int ans = 0;
	for(int i=0; i<N; i++) {
		ans = max(ans, total-alone[i]);
	}
	cout << ans << nl;
}
