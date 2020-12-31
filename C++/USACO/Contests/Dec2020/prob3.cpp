#include <bits/stdc++.h>
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;

struct cow {
	int x, y;
	char d; // direction, either N (north) or E (east)
	bool moving = true;
	int traveled = -1;
	bool cmp(const cow &c) {
		return (x==c.x) && (y==c.y);
	}
};

bool cmp_x(const cow &a, const cow &b) {
	return a.x < b.x;
}

bool cmp_y(const cow &a, const cow &b) {
	return a.y < b.y;
}

int N;
vector<cow> east, north;
cow cows[55];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) {
		cow c;
		cin >> c.d >> c.x >> c.y;
		if (c.d=='E')
			east.pb(c);
		else
			north.pb(c);
		cows[i] = c;
	}
	if (N==1||east.size()==0||north.size()==0) {
		forn(i,N)
			cout << "Infinity" << nl;
		return 0;
	}

	sort(north.begin(),north.end(),cmp_x);
	sort(east.begin(),east.end(),cmp_y);
	for (cow &a: north) {
		for (cow &b: east){
			if (b.x < a.x && b.y > a.y && b.moving && a.moving){
				// cout << a << nl << b << nl;
				int meet_x = a.x, meet_y = b.y;
				if (meet_x-b.x>meet_y-a.y) {
					b.moving = false;
					b.traveled = meet_x-b.x;
				} else if (meet_x-b.x==meet_y-a.y){
					b.traveled = meet_x-b.x;
					a.traveled = meet_y-a.y;
				} else {
					a.traveled = meet_y-a.y;
					a.moving = false;
				}
			
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (cow c: north){
			if (cows[i].cmp(c))
				cows[i] = c;
		}
		for (cow c: east){
			if (cows[i].cmp(c))
				cows[i] = c;
		}
		if (cows[i].moving)
			cout << "Infinity" << nl;
		else 
			cout << cows[i].traveled << nl;
	}
}