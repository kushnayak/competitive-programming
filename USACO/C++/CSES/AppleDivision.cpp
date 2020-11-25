#include <iostream>
#include <vector>
#include <limits>
#define FOR(n) for (int i=0; i<n; ++i)
using namespace std;

const int MAX = 1e9;

int n = 0, S[MAX];
int sum = 0, ans = numeric_limits<int>::max();

void search(vector<int> &sub, int i) {
	if (i==n) {
		int cur_sum = 0;
		for (int num: sub){
			// cout << num << " ";
			cur_sum += num;
		}
		// cout << "\n";
		ans = min(ans, abs(sum - 2*cur_sum));

	} else {
		sub.push_back(S[i]);
		search(sub, i+1);
		sub.pop_back();
		search(sub, i+1);
	}
}
int main() {
	cin >> n;
	
	FOR(n){
		cin >> S[i];
		sum += S[i];
	}

	vector<int> sub;
	search(sub, 0);
	// cout << "sum: " << sum << '\n';
	cout << ans << '\n';
}

