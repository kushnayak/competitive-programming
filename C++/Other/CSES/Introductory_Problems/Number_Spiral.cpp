#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;
using ll = long long;

ll T, x, y;
 
ll query(){
	if(x==1&&y==1){
		return 1;		
	}
	ll pos = max(x,y);
	ll corner = pos*pos;
	ll cornerx, cornery;
	cornery = pos, cornerx = 1;
	if(pos%2==1) swap(cornery, cornerx);
	return corner-(abs(cornerx-x)+abs(cornery-y));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while(T--){
		cin >> y >> x;
		cout << query() << nl;
	}
}