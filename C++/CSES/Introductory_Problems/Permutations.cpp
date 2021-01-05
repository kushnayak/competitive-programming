#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
using namespace std;
using ll = long long;

int N;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	if(N==1){
		cout << 1 << nl;
		return 0;
	}
	if(N<4){
		cout << "NO SOLUTION" << nl;
		return 0;
	}
	if(N==4){
		cout << "2 4 1 3" << nl;
		return  0;
	}
	if(N%2==0){
		for(int i=N; i>=2; i-=2){
			cout << i << " ";
		}
		for(int i=N-1; i>=1; i-=2){
			cout << i;
			i==1? cout << nl : cout << " ";
		}
	} else{
		for(int i=N; i>=1; i-=2){
			cout << i << " ";
		}
		for(int i=N-1; i>=2; i-=2){
			cout << i;
			i==2? cout << nl : cout << " ";
		}
	}
}