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

const int maxN=2e5+5;
int N, M, K, a[maxN], b[maxN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	forn(i,N) cin >> a[i]; 
	forn(i,M) cin >> b[i];
	sort(a,a+N); sort(b,b+M);
	int i=0, j=0, ans=0;
	while(i<N && j<M){
		if(abs(a[i]-b[j])<=K){
			i++; j++; ans++;
		} else if(a[i]-b[j]>K){
			j++;
		} else{
			i++;
		}
	}
	cout << ans << nl;
}

