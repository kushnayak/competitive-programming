#include <iostream>
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_]; if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)

using namespace std;

// n can be global var, does not affect algo only processing 
void heapPermutation(int a[], int n, int size) {

	if (size == 1) {
		//process permutation
		print_arr(a, 4);
		return;
	}

    for (int i = 0; i < size; i++) {
    	heapPermutation(a, size - 1, n);

    // if size is odd, swap 0th i.e (first) and 
    // (size-1)th i.e (last) element
		if (size % 2 == 1)
		    swap(a[0], a[size - 1]);

    // If size is even, swap ith and 
    // (size-1)th i.e (last) element
		else
			swap(a[i], a[size - 1]);
	}

}



int main() {
	int a[] = {1,2,3,4};
	heapPermutation(a, 4, 4);
}