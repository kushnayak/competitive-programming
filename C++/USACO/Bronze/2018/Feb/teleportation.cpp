#include <bits/stdc++.h>
#define FOR(i, b) for (int i=0; i<b; i++)
#define nl '\n'
using namespace std;


void setIO(string name = "") { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if(name.size()){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
  }
}

int a, b, x, y;

int main() {
	setIO("");

	cin >> a >> b >> x >> y;

	cout << min(abs(a-b), min(abs(a-x)+abs(b-y), abs(a-y) + abs(x-b))) << nl;


}
