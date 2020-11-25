#include <bits/stdc++.h>

#define print_arr(arr, N) for (int _=0; _<N; _++) cout << arr[_] << " " 
using namespace std;

#define cin fin 
#define cout fout

ifstream fin("photo.in");
ofstream fout("photo.out");

int N, a[1000], b[1000];

bool valid() {
	bool used[1000] = {0};
	for (int i=0; i<N; i++){
		if (a[i] < 0 || a[i] > N) 
			return false;
		used[a[i]] = 1;
	}
	for (int i=1; i<=N; i++)
		if (!used[i])
			return false;
	return true;
}

int main() {
	cin >> N; 

	for (int i=0; i<N-1; i++)
		cin >> b[i];

	// cout << "\n";
	for (int i=0; i<N; i++) {

		a[0] = i+1;

		for (int j=1; j<N; j++)
			a[j] = b[j-1] - a[j-1];

		// print_arr(a, N); cout << "\n";

		if (valid()){
			for (int j=0; j<N; j++){
				cout << a[j];
				if (j != N-1)
					cout << " ";
			}
			cout << '\n';
			return 0;
		}

	}
}
