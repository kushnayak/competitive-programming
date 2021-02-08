#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;
using ll=long long;

ll N, grid[1001][1001], row, col;

/*
Solution:
http://www.usaco.org/current/data/sol_prob3_silver_jan21.html
Each valid arrangement can be created by either alternating cow,no cow
in each row or in each column. Take max of each alternation for each row 
and col and take max of total max row,col.
*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) forn(j,N) cin >> grid[i][j];
	forn(i,N){
		ll even=0,odd=0;
		forn(j,N){
			if(j%2==0) even+=grid[i][j];
			else odd+=grid[i][j];
		}
		row+=max(odd,even);
	}
	forn(j,N){
		ll even=0,odd=0;
		forn(i,N){
			if(i%2==0) even+=grid[i][j];
			else odd+=grid[i][j];
		}
		col+=max(odd,even);
	}
	cout << max(row,col) << nl;

}

