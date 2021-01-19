#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;
using ll = long long;

ll N, K;


void solve(){
	ll total = ((K*K)*(K*K-1))/(2); // K^2 choose 2  ways to place knights
	ll attack = 4*(K-2)*(K-1);
	//(K-3+1)*(K-2+1) ways to make 3*2 boxes in K*K grid, *2 because you can also do 2*3 boxes,
	//and in each 3*2 box, there are 2 ways to arrange knights, each on top/bottom corners
	cout << total-attack << nl;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for(K=1; K<=N; K++) solve();
}