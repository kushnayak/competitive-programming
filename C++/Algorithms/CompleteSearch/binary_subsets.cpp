// O(n2^n) but cooler to write than recursive sub

#include <bits/stdc++.h>

#define nl '\n'
#define sz(v) (int)(v).size()

using namespace std;

int N; 

string binary(int a){
	string ret=""; 
	for(int i=N; i>=0; --i){
		if((1<<i)&a)
			ret.push_back('1'); 
		else 
			ret.push_back('0'); 
	}
	return ret; 
}

int main() {
	int arr[] = {1,2,3,4,5,6}; 
	N=sizeof arr / sizeof arr[0]; 

	/*
	go through values of 0 ... 2^N, binary representation of each value represents 
	every subsets, where at pos i, 1 represents inclusion of an element at i and 
	conversely 0 represents exclusion of element
	*/

	for(int b=0; b<(1<<N); ++b){
		cout << b << " binary: " << binary(b) << nl; 
		vector<int> sub; 
		for(int i=0; i<N; ++i) 
			if(b&(1<<i))
				sub.push_back(arr[i]); 
		cout << "subset: "; 
		for(int i=0; i<sz(sub); ++i) cout << sub[i] << " \n"[i==sz(sub)-1]; 
		cout << nl; 
	}	
}

