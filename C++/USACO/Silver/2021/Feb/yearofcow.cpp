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

int N, K; 
set<int> cycle; 
vector<int> gaps; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K; 
	forn(i,N){ int a; cin >> a; cycle.insert((a+11)/12); }
	int answer = *cycle.rbegin(); 
	int last = 0; 
	while(!cycle.empty()){
		gaps.pb(*cycle.begin()-last-1); 
		last = *cycle.begin(); 
		cycle.erase(cycle.begin()); 
	}
	sort(gaps.begin(), gaps.end(), greater<int>()); 
	for(int i=0; i<K-1 && i<sz(gaps); ++i)
		answer -= gaps[i]; 
	cout << answer * 12 << nl; 
}

