/*
ID: kushnay1
TASK: transform
LANG: C++                 
*/
#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N;
char grid[12][12], trans[12][12], temp[12][12], final[12][12];

void dbg(char arr[][12]){
	forn(i,N){
		forn(j,N) cout << arr[i][j];
		cout << nl;
	}
}

void reset(){ forn(i,N) forn(j,N) trans[i][j]=grid[i][j];}
bool same(){
	forn(i,N) forn(j,N) if(final[i][j]!=trans[i][j]) return false;
	return true;
}
void rotate90(){
	for(int r=0,c1=0; c1<N; c1++,r++){
		for(int c=0,r1=N-1; r1>=0; r1--,c++){
			temp[r][c]=trans[r1][c1];
		}
	}
	forn(i,N) forn(j,N) trans[i][j]=temp[i][j];
}

void reflect(){
	for(int row=0; row<N; row++){
		int l=0, r=N-1;
		while(l<=r){
			swap(trans[row][l],trans[row][r]);
			l++; r--;
		}
	}
}

int check(){
	reset();
	rotate90();
	if(same()) return 1;

	reset();
	forn(i,2) rotate90(); 
	if(same()) return 2;

	reset();
	forn(i,3) rotate90(); 
	if(same()) return 3;

	reset();
	reflect(); 
	if(same()) return 4;

	reset();
	reflect();
	rotate90(); 
	if(same()) return 5;
	reset();
	reflect();
	forn(i,2) rotate90(); 
	if(same()) return 5;
	reset();
	reflect();
	forn(i,3) rotate90(); 
	if(same()) return 5;

	reset();
	if(same()) return 6;
	return 7;
}

int main() {
	IO("transform");
	cin >> N; 
	forn(i,N) forn(j,N) cin >> grid[i][j];
	forn(i,N) forn(j,N) cin >> final[i][j];
	cout << check() << nl;
}

