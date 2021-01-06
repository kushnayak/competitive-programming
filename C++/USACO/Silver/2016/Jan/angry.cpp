#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

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
We know that if a radius R does not work, then radius r < R will also not work, meaning the function 
is montonic. Becuase of this we can binary search on the minimum r value. To check if some r value 
works, we know that the radius must be at the max position - r so it can reach there. So we just
sort the array, check the max value and know position a must be at max - r, detonate position a, 
find the next max and repeat and return if our total a values ≤ K.
Time complexity: O(2nlogn) -> O(nlogn)
*/
const int maxN = 50004;
int N, K, cow[maxN];
bool open[maxN];

bool possible(int r) {
	int used = 0;
	int mx = N-1;
	while(mx>=0){
		int at = cow[mx]-r; // which location we detonate at
		while(mx >= 0 && abs(cow[mx]-at)<=r)
			mx--;
		used++;
	}
	// cout << used << nl;
	return used <= K;
}

ll search(){
	ll pos = 0, high = 2e9;
	for(ll a=high; a>=1; a/=2)
		while(!possible(pos+a)) pos += a;
	return pos + 1;
}
int main() {
	IO("angry");
	cin >> N >> K;
	forn(i,N) cin >> cow[i];
	sort(cow,cow+N);
	cout << search() << nl;
}

