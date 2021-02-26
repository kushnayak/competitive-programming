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

int N;

void solve(){
	cin >> N;
	int days=2;
	double ans;
	while(ans=N/(pow(2,days)-1), ans!=(int)ans || ans<0){ days++; }
	cout << (int)ans << nl;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) solve();
}

