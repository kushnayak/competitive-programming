#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int N, l[100000];

int main() {
	IO("lemonade");
	cin >> N;
	forn(i,N)
		cin >> l[i];
	sort(l, l+N, [](const int a, const int b){return a > b;});
	int ans = 0, i=0, sz=0;
	vector<int> line;
	while (true) {
		if (sz<=l[i])
			line.push_back(l[i]), ans++, sz++, i++;
		else 
			break;
	}
	cout << ans << nl;
}
