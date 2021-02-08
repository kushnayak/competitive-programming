#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;

/*
Binary search:
lower_bound(begin,end,val)
lower_bound returns first element ≥ value, if not end()
upper_bound returns first element > value, if not end()

upper_bound(val) - lower_bound(val) returns the number of val occurences 

to see what index the iterator returned is, do upper_bound/lower_bound - arr/arr.begin()

Reverse binary search:
when used with a decreasing array and upper_bound/lower_bound(begin,end,val,greater<int>())
lower_bound returns first element ≤ value
upper_bound returns first element < value

to get reverse binary search for containters like multiset, set, 
you can just do multiset<int,greater<int>> and do normal set.lower_bound()

*/

int arr[]={323,32,2,3,4,3,532};
int N=sizeof(arr)/sizeof(arr[0]);

void print(){forn(i,N)cout << arr[i] << " \n"[i==N-1]; }

int main(){
	sort(arr,arr+N);
	cout << "binary search:" << nl;
	print();
	cout << *lower_bound(arr,arr+N,4) << nl;
	cout << *upper_bound(arr,arr+N,4) << nl;

	sort(arr,arr+N,greater<int>());
	cout << nl << "reverse binary search:" << nl;
	print();
	cout << *lower_bound(arr,arr+N,4,greater<int>()) << nl;
	cout << *upper_bound(arr,arr+N,4,greater<int>()) << nl;

}