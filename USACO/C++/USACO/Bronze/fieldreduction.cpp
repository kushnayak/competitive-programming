#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 400000
#define MAX 400000
#define cin fin 
#define cout fout

ifstream fin("reduce.in");
ofstream fout("reduce.out");

int N, x[50000], y[50000];
ll ans = INT64_MAX;

int max_arr(int arr[], int avoid = -1) {
	int ret = 0, ind = 0;
	for (int i=0; i<N; i++){
		if (i == avoid){
			continue;
		} else {
			if (arr[i] > ret) {
				ret = arr[i];
				ind = i;
			}
		} 
			
	}
	return ind;
}

int min_arr(int arr[], int avoid = -1) {
	int ret = MAX, ind = 0;
	for (int i=0; i<N; i++){
		if (i == avoid){
			continue;
		} else {
			if (arr[i] < ret) {
				ret = arr[i];
				ind = i;
			}
		} 
			
	}

	return ind;
}

int area(int avoid) {
 	return (x[max_arr(x, avoid)] - x[min_arr(x, avoid)]) * (y[max_arr(y, avoid)] - y[min_arr(y, avoid)]);
}

void solve() {
	ans = min(min(area(max_arr(x)), area(max_arr(y))), min(area(min_arr(x)), area(min_arr(y))));
}

int main() {
	
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> x[i] >> y[i];
	}

	solve();
	cout << ans << "\n";
}
