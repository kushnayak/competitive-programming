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

const int maxN = 1e5+5; 
#define f first
#define s second 

int N, M;
int pos[maxN]; 
int ans[maxN]; 
pii fav[maxN];

int main() {
	IO("cereal");
	cin >> N >> M; 
	forn(i,N) cin >> fav[i].f >> fav[i].s; 
    int tot = 0; 
    memset(pos, -1, sizeof(ans[0])*maxN); 
    for(int i=N-1; i>=0; --i){
        int want = fav[i].f; 
        int at = i; 
        while(true){
            if(pos[want] == -1){
                tot++; 
				pos[want] = at; 
                break; 
            } else if(pos[want] > at){
            	int temp = pos[want]; 
            	pos[want] = at; 
            	want = fav[temp].s; 
            	at = temp; 
            } else {
            	break; 
            }
        }
        ans[i] = tot; 
    }
    for(int i=0; i<N; ++i) cout << ans[i] << nl; 
}

