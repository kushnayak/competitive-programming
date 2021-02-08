#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define nl '\n'

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int arr[]={1,2,3,4,5,45,345,345435};
	int N=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+N,greater<int>());
	for(int i=0; i<N; i++) cout << arr[i] <<" \n"[i==N-1];
	cout << arr+N-lower_bound(arr,arr+N,400,greater<int>()) << nl;
}

