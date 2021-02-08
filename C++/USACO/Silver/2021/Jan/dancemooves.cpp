#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define sz(v) (int)(v).size()
using namespace std;
using gpset=gp_hash_table<int,null_type>;

const int maxN=1e5+5;
int N, K, arr[maxN], to[maxN], comp[maxN];
gpset path[maxN], ans[maxN];

/*
Solution:
Very similar to problem swapity swapity swap http://www.usaco.org/index.php?page=viewproblem2&cpid=1014.
First simulate first K swaps then track to which location each index arrives. Using this we will be 
having disjoint cycles where the positions will continually visit. While swapping each index make sure
to track the path of each index in an unordered set. Now for each index follow the cycle and maintain 
an unordered set storing the visited locations for each component. Answer is the size of each cycle 
size. 
Time complexity: O(N+K)
*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	forn(i,N){ arr[i]=i; path[i].insert(i); }
	forn(i,K){
		int a,b; cin >> a >> b; a--; b--;
		path[arr[a]].insert(b);
		path[arr[b]].insert(a);
		swap(arr[a],arr[b]);
	}
	forn(i,N){
		to[arr[i]]=i;
	}
	// forn(i,N){ cout << to[i] << " \n"[i==N-1];}
	// forn(i,N){
	// 	cout << "pos " << i+1 << " to " << to[i]+1 << nl;
	// 	cout << "path" << nl;
	// 	for(int u: path[i])
	// 		cout << u+1 << nl;
	// }
	int cmp=1;
	forn(i,N) if(!comp[i]) {
		int ptr=i;
		// cout << "starting at " << i << nl;
		do{
			comp[ptr]=cmp;
			for(int u: path[ptr]) ans[cmp].insert(u);
			ptr=to[ptr];
			// cout << "goes to " << ptr << nl;
		} while(ptr!=i);
		cmp++;
	}
	forn(i,N) cout << sz(ans[comp[i]]) << nl;
}

