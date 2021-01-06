#include <bits/stdc++.h>
#define newline cout << "\n"
using namespace std;

#define cin fin 
#define cout fout

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int N, from[100], to[100], covered[1000], ans=0;


int main() {
	cin >> N; 
	for (int i=0; i<N; i++) {
		cin >> from[i] >> to[i];
		for (int j=from[i]; j<to[i]; j++)
			covered[j]++;
	}

	for (int i=0; i<N; i++) {
		int curr = 0;

		for (int j=from[i]; j<to[i]; j++)
			covered[j]--;

		for (int j=0; j<1000; j++)
			if (covered[j] > 0)
				curr++;

		for (int j=from[i]; j<to[i]; j++)
			covered[j]++;

		ans = max(ans, curr);
	}

	cout << ans << "\n";
}
