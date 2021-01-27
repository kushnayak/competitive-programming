#include <bits/stdc++.h>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'
#define sz(v) (int)v.size()
using namespace std;
using ll = long long;

int N;
vector<int> first, second;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	if(N==3){
		cout << "YES" << nl;
		cout << "2\n1 2\n1\n3\n"; 
	}
	if(N%4==0){
		int l=0, r=N+1;
		for(int rep=1; rep<=2; rep++){
			for(int i=0; i<N/4; i++){
				l++; r--;
				vector<int> &add = rep==1 ? first: second;
				add.push_back(l);
				add.push_back(r);
			}
		}
	} else if((N-1)%2==0 && ((N-1)/2)%2==1){
		int l=0, r=N;
		for(int i=0; i<(N-1)/2; i++){
			l++, r--;
			first.push_back(l); 
			first.push_back(r);
		}
		first.push_back(N);
		for(int i=0; i<(N-1)/2+1; i++){
			l++, r--;
			second.push_back(l);
			second.push_back(r);
		}
	} else{
		cout << "NO" << nl;
		return 0;
	}
	cout << "YES" << nl;
	cout << sz(first) << nl;
	for(int i=0; i<sz(first); i++) 
		cout << first[i] << " \n"[i==sz(first)-1];
	cout << sz(second) << nl;
	for(int i=0; i<sz(second); i++) 
		cout << second[i] << " \n"[i==sz(second)-1];
}