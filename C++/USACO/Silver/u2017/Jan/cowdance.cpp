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
First thing is to create a check function that given a K value will return if the cows will be able 
to finish in less than T time. This can be done using a priority queue; we know that the cow with 
the min dancing time will be the first to leave, so we can take that value and add to subsequent cows
to represent their time, and if that "last time" + curr cow time > T then we know that this K cannot work.
This check function takes O(nlogk) per call. Now we can go through each n cows, which would be 
O(n^2logk) time, but another observation we can make is that this check function montonically increases
(i.e. if some value K value a works, then all values greater then a should also work because it will 
only have less T, and if some K value a is false, then we know that taking less then a values will not 
change this). Given this we can binary search on the answer.
Time complexity: O(nlogklogn)
*/
const int maxN = 10005;
int N, T, dance[maxN];
bool in[maxN];

int check(int K) {
	int last = 0;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0; i<N; i++){
		if(sz(q)==K) {
			last = q.top();
			q.pop();
		} 
		if(last+dance[i]>T) {
			return false;
		}
		q.push(last+dance[i]);
		// cout << "size of q:" << sz(q) << " q top:" << q.top() << nl;
	}
	return true;
}

int search() { // we have to find min x
	int low = 1, high = N;
	while(low<high){
		int mid = (high+low)/2;
		if(check(mid)){  //if mid works, then ans has to be mid or below mid
			high = mid;
		} else { // if mid does not work, we know everything including mid will not work
			low = mid+1;
		}
	}
	return low;
}
int main() {
	IO("cowdance");
	cin >> N >> T;
	forn(i,N) cin >> dance[i];
	cout << search() << nl;
}

