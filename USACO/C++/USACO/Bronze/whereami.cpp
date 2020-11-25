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

int N; string road;

bool possible(int len) {
	set<string> poss;
	for (int i=0; i<=N-len; i++){
		poss.insert(road.substr(i, len));
	}
	return poss.size() == N-len+1;
}

int main() {
	setIO("whereami");
	cin >> N >> road;
	
	for (int len=1; len<=N; len++) {
		// cout << len << nl;
		if (possible(len)){
			cout << len << nl;
			return 0;	
		}
	}


}
