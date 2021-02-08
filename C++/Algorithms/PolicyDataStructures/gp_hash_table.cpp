#include <bits/stdc++.h>

//------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//------------------------------------------------
using namespace std;
#define nl '\n'


// basically same functions as unordered_map

int main() {
	gp_hash_table<int,null_type> uset; // for unordered set
	gp_hash_table<int,int> umap; // unordered map
	uset.insert(10); 
	umap.insert(make_pair(1,2)); umap[6]=8; umap.insert({4,5});
	if(umap.find(4)!=umap.end()){
		cout << " found " << nl;
	}
}

