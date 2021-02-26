#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N, K, b[1005], give[1005], ans, maxb;

/*
Solution: If we give elsie a minimum of g berries in all of her baskets, then it would
be most optimal to give only g berries to her in each basket and fill the rest ≤ g for
belsie. So just go through every possible g value and simulate from their giving k/2
g chunks to elsie and giving the rest max possible to belsie.
*/
int main() {
	IO("berries");
	cin >> N >> K;
	forn(i,N){ cin >> b[i]; maxb=max(maxb,b[i]);}

	for(int g=1; g<=maxb; g++){
		forn(i,g+1) give[i]=0;
		forn(i,N){ give[g]+=b[i]/g; give[b[i]%g]++; }


		if(give[g]<K/2){ break; }
		give[g]-=K/2;

		int i=g, total=0, basket=0;

		while(i>0 && basket<K/2){
			if(give[i]>0){
				basket++;
				total+=i;
				give[i]--;
			} else{
				i--;
			}
		}

		if(basket==K/2) ans=max(ans,total);
	}
	cout << ans << nl;
}

