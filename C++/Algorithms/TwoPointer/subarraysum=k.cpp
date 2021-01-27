//O(n) (Amortized)
#include <iostream>
using namespace std;

int arr[] = {6,3,6,8,2,5}, N=sizeof(arr)/sizeof(arr[0]), X=6;
int main(){

	int l=0, r=0, sum=0;
	for(; r<N; r++){
		sum += arr[r];
		while(sum>X && l<=r){
			sum -= arr[l];
			l++;
		}
		if(sum==X) ans++; //or break if one subarray sum is needed
	}
	cout << ans << nl;
}