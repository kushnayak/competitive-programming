// O(n!)
#include <iostream>
#include <algorithm>

using namespace std;

// array passed as pointers 
void check(int a[], int n) {
	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << '\n'; 
}

int main() {
	int arr[] = {1,2,3,4};
	int n = 4;
	do {
		check(arr, n);
	} while (next_permutation(arr, arr+n));
	//next perm takes in pointers to arr, for vector is v begin, v end
	// finds next lexographical order so string/arr must be sorted
}



