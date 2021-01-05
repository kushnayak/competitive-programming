#include <bits/stdc++.h>

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

int N;
unordered_set<int> uset;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) {int a; cin >> a; uset.insert(a);}
	cout << sz(uset) << nl;
}

