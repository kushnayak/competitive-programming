/*
ID: kushnay1
TASK: namenum
LANG: C++                 
*/
#include <bits/stdc++.h>
#define in(f) if (fopen(f "", "r")) freopen(f "","r",stdin)
#define out(f) if (fopen(f "", "w")) freopen(f "","w",stdout)

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int dictsz=4617;
string names[dictsz];
unordered_map<char,vector<char>> id = {
	{'2', {'A','B','C'}},
	{'3', {'D','E','F'}},
	{'4', {'G','H','I'}}, 
	{'5', {'J','K','L'}},
	{'6', {'M','N','O'}},
	{'7', {'P','R','S'}},
	{'8', {'T','U','V'}},
	{'9', {'W','X','Y'}}  
};

string s; 
int N;
vector<string> ans;
void dfs(string res, int index){
	if(index==N){
		if(binary_search(names,names+dictsz,res)){
			ans.pb(res);
		}
		return;
	}
	for(char c: id[s[index]])
		dfs(res+c,index+1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	in("dict.txt");
	forn(i,dictsz) cin >> names[i];
	in("namenum.in");
	out("namenum.out");
	cin >> s;
	N=sz(s);
	dfs("",0);
	if(sz(ans))
		for(string name: ans)
			cout << name << nl;
	else 
		cout << "NONE" << nl;
}

