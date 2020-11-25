#include <bits/stdc++.h>
#define FOR(i, b) for (int i=0; i<b; i++)
#define nl '\n'
using namespace std;

int N, K, session[10][20];

void setIO(string name = "") { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if(name.size()){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
  }
}

int where(int prac_session, int a) {
	for (int i=0; i<N; i++)
		if (session[prac_session][i] == a)
			return i;
	return -1;
}

bool valid(int a, int b) {
	for (int i=0; i<K; i++) {
		if (!(where(i, a) < where(i, b)))
			return false;
	}
	return true;
}

int main() {
	setIO("gymnastics");

	cin >> K >> N;
	FOR(i, K)
		FOR(j, N)
			cin >> session[i][j];

	int pairs = 0;

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++){
			if (j==i)
				continue;
			if (valid(i,j))
				pairs++;
		}
	}

	cout << pairs << "\n";

}
