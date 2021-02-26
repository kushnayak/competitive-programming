#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()

#define nl '\n'
#define pb push_back

using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define p first
#define isusb second

int usb, ps2, both, m;
pair<int,bool> mouse[(int)3e5+5];
ll taken, cost;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> usb >> ps2 >> both >> m;
	forn(i,m){
		int a; string s; 
		cin >> a >> s;
		mouse[i]={a,s=="USB"};
	}
	sort(mouse,mouse+m);
	int i=0;
	while(i<m && (usb || ps2 || both)){
		if(mouse[i].isusb && usb){ cost+=mouse[i].p; --usb; taken++; }
		else if(!mouse[i].isusb && ps2){ cost+=mouse[i].p; --ps2; taken++; }
		else if (both){ cost+=mouse[i].p; --both; taken++; }
		++i; 
	}
	cout << taken << " " << cost << nl;
}

