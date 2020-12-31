//O(nm) where n is rows and m is columns of matrix
// Good explanation: https://youtube.com/watch?v=PwDqpOMwg6U
#include <iostream>
#define nl '\n'
using namespace std;
using pii = pair<int,int>;

int N = 3, M = 3; // N * M matrix
int arr[3][3] = {{0,0,0},{1,2,4},{4,3,6},{3,4,5}};
int dp[N+1][M+1]; // prefix and original array; 1-based index to prevent out of bounds

void generatePrefix(){
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++) 
			dp[i][j] = arr[i][j] + dp[i-1][j]
			+ dp[i][j-1] - dp[i-1][j-1];
}

int querySum(int r1, int c1, int r2, int c2) { 
	return dp[r2][c2] + dp[r1-1][c1-1] 
	- dp[r2][c1-1] - dp[r1-1][c2];
}