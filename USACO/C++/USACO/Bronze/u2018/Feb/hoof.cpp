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

// find all cows with 0 in-degrees (no incoming edges) and
// all cows that form a cycle with 1 in-degree as they will 
// only pass to each other 

int N, cows[100], received[100];

int target(int i) {
	int left_nbr = -1, left_dist = 1000;
	int right_nbr = -1, right_dist = 1000;

	for (int j=0; j<N; j++){
		if (cows[j] > cows[i] && cows[j] - cows[i] < right_dist){
			right_dist = cows[j] - cows[i];
			right_nbr = j;
		}  
		if (cows[j] < cows[i] && cows[i] - cows[j] < left_dist) {
			left_dist = cows[i] - cows[j];
			left_nbr = j;
		}
	}

	if (left_dist <= right_dist)
			return left_nbr;
		return right_nbr;


}
int main() {
	setIO("");

	cin >> N;
	for (int i=0; i<N; i++)
		cin >> cows[i];

	for (int i=0; i<N; i++)
		received[target(i)]++;

	int ans = 0;

	for (int i=0; i<N; i++) {
		if (received[i] == 0)
			ans++;
		// i < target(i) is there to make sure we do not double count the oscillations, because we can count them from 2 different nodes
		// guarantees we only count the nodes the oscillate with a node ahead of it we haven't counted
		if (received[i] == 1 && received[target(i)] == 1 && i < target(i) && target(target(i)) == i){
			cout << "i " << i << " target(i) " << target(i) << nl;
			ans++;
		}
	}

	cout << ans << nl;


}









