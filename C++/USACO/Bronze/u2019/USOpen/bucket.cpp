#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define endl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define x second
#define y first
#define mp(a,b) make_pair(a,b)
using namespace std;
using pii = pair<int, int>;

int main() {
	IO("buckets");

	pii barn, rock, lake;

	forn(i, 10) {
		string line; cin >> line;
		forn(j, 10) {
			if (line[j] == 'B') barn = mp(i, j);
			if (line[j] == 'R') rock = mp(i, j);
			if (line[j] == 'L') lake = mp(i, j);
		}
	}

	int dist = abs(barn.x - lake.x) + abs(barn.y - lake.y) - 1;

	if (((barn.x == lake.x && lake.x == rock.x) || (barn.y == lake.y && lake.y == rock.y)) 
		&& abs(barn.x - rock.x) + abs(barn.y - rock.y) +  abs(lake.x - rock.x) + abs(lake.y - rock.y) ==  dist + 1)
		dist += 2;


	cout << dist << endl;

	
}
