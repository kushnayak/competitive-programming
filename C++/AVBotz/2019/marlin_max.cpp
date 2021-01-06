#include <iostream>
#include <cstdio>
#define forn(i,n) for(int i=0; i<n; i++)
using namespace std;

int N, in, mx[3]={0}, ind[3];

int main() {
	cin>>N;
	forn(i,N) forn(j,3) if(cin>>in, in>mx[j]){
		ind[j]=i; mx[j]=in; if(j!=2)cin.ignore(1);
	}	
	forn(i,3) cout << ind[i] << " \n"[i==2]; 
}