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
#define start second
#define end first

int N, ans; 
pii times[(int)2e5];

bool cmp(const pii &a, const pii &b){
	if(a.end==b.end) return a.start < b.start;
	return a.end < b.end;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> times[i].start >> times[i].end;
	sort(times,times+N,cmp);
	int prev_end = -1;
	forn(i,N){
		if(times[i].start>=prev_end){
			ans++; prev_end=times[i].end;
		}
	}
	cout << ans << nl;
}

