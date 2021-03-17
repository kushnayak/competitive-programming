//O(n)
//Kadane's algorithm to find maximum subarray sum
//Good explanation: https://www.youtube.com/watch?v=2MmGzdiKR9Y
#include <iostream>
#define nl '\n'
using namespace std;

int arr[] = {1,2,3,4,-5,-10,6,10}, N = sizeof(arr)/sizeof(arr[0]), local = 0, global = 0;
int main(){
/*	Given a position i, and a sum a which represents the 
	maximum subarray sum ending at position i-1, the locally
	optimal choice would be either to continue that sum a with i
	or just take i. Taking the max of all local maxes gives optimal max
	Local = max(0,local+arr[i]) because if local+arr[i] <= 0 then it
	will always be optimal to take arr[i+1] by itself bc <0 would hurt it.
		//local should always be > 0 to continue optimal subarray, you would only take 
		//arr[i] itself as max subarray if max subarray ending in i-1<0
	*/
	for(int i=0; i<N; i++){
		local = max(0,local+arr[i]); 
		global = max(global,local);
		cout << "arr i:" << arr[i] << " local:" << local << " global:" << global << nl; 
	}
	cout << global << nl;
}