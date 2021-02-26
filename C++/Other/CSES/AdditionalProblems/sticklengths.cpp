#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

/*sol: Huffman coding*/

int X, N;
ll ans;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> X >> N;
	forn(i,N){ int n; cin >> n; pq.push(n); }
	for(int i=1; i<N; i++){
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();
		pq.push(a+b);
		ans+=a+b;
	}
	cout << ans << nl;
}

