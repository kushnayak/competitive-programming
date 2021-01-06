#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_];if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define f first
#define s second
#define pb push_back
#define ub upper_bound
#define lb lower_bound

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

/* 
Solution:
First observation to make is that the function is monotonic; if some maximum T waiting value for 
any cow is impossible then it will not be possible for any values above T to be valid maximum 
waiting times. Given this we can binary search on finding the min T waiting value that we can 
put all the cows in and no waiting time between any cows is > T. Now to create a possible function
that checks whether some value T works: we need to first sort the time values then greedily
process C cows if possible, else process cows till some cow j time - cow i time ≤ T. If we were
able to get through processing all cows without running out of cars, this T is valid.
Time complexity: O(2nlogn) -> O(nlogn) 
*/
const int maxN = 1e5;
int N, M, C, t[maxN];

bool possible(int T) { //returns true if max min of T can be achieved; greedy
	int cars = M;
	for(int i=0; i<N; i++) {
		if(!cars) return false;
		if(i+C-1<N && t[i+C-1]-t[i]<=T) {
			// cout << "taken " << t[i] << " to " << t[i+C-1] << nl;
			i += C-1;
		} else {
			int j = i;
			while(j<N && t[j]-t[i]<=T){
				j++;
			}
			// cout << "instead taken " << i << " to " << j-1 << nl;
			i = j-1;
		}
		cars--;
		// cout << "cars left " << cars << nl;
	}
	return true;
}

int search() {
	int pos = 0, max = 1e9+5;
	for(int a=max; a>=1; a/=2){
		while(!possible(pos+a)) 
			pos += a;
		// cout << "pos: " << pos << nl;
	}
	return pos+1;
}
int main() {
	IO("convention");
	cin >> N >> M >> C;
	forn(i,N) cin >> t[i];
	sort(t,t+N);
	// print_arr(t,N);
	// cout << possible(5) << nl;
	cout << search() << nl;
}

