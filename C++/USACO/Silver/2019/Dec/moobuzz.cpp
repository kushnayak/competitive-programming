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

ll N; 
ll arr[] = {14, 1, 2, 4, 7, 8, 11, 13}; 

/*
find which row of 15 numbers the nth num is on then add
it to the the column on which it starts (N%8) 
*/
int main() {
	IO("moobuzz");
	cin >> N; 
	cout << ((N-1)/8)*15 + arr[N%8] << nl;
}

