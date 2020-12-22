#include <bits/stdc++.h>
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int N, flowers[105], ans=0;

bool valid(int a, int b) {
	double sum = 0, avg_cmp=0;
	int avg = 0;
	for(int i=a; i<=b; i++) sum+=flowers[i];
	avg_cmp = sum/(b-a+1);
	if (int(avg_cmp)==avg_cmp) 
		avg = int(avg_cmp);
	else 
		return false;
	// cout << "sum: " << sum << " average: " << avg << nl;
	for (int i=a; i<=b; i++)
		if (flowers[i]==avg)
			return true;
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> flowers[i];
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++){
			if (valid(i,j)) {
				// cout  << i << " " << j << nl;
				ans++;
			}
		}
	}
	cout << ans << nl;
}
