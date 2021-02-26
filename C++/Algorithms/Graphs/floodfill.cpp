#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;

const int maxN=255, dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
int grid[maxN][maxN]; 
int N, M; 
bool visited[maxN][maxN];
int cursize = 0; 

void floodfill(int r, int c, int color){
	if(r<0 || r>=N || c<0 || c >=M) return; // if outside grid
	if(grid[r][c] != color) return; // wrong color
	if(visited[r][c]) return; // already visited this square
	visited[r][c] = true; // mark current square as visited
	cursize++; // increment the size for each square we visit
	// recursively call floodfill for neighboring squares
	for(int y: dy)
		for(int x: dx)
			ff(r+y,c+x,color);
}

int main() {

	forn(i,N)
		forn(j,N)
			if(!visited[i][j]){
				cursize=0;
				ff(i,j,grid[i][j]);
			}
}

