#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define nl '\n'

using namespace std;
using pii=pair<int,int>;
using ll=long long;
#define x first
#define y second

/*Solution:
First sort the points by x coordinates, then sweep through each pair of points.
These 2 points will be the 2 y parallel sides of the rectangle. Maintain a 2d prefix
sum for the number of points above point i at all points j for all points i. Do the same
for  below. These points can extend the x parallel sides up or down, creating more subsets.
Now the nubmer of rectangles possible with the 2 sides and above and below is (top+1) choices 
(+1 not including any point) * (bottom+1) same thing for +1. Note this formula works only because 
all x and y are distinct so there can never be multiple points above an x coordinate with the same y 
so it is possible to make these combinations.
Time complexity:O(n^2+nlogn)
*/
const int maxN=2505;
bool cmp_x(const pii& a, const pii& b){ return a.x<b.x; }

pii coords[maxN];
int above[maxN][maxN], below[maxN][maxN];
ll N,ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	forn(i,N) cin >> coords[i].x >> coords[i].y;

	sort(coords,coords+N,cmp_x);
	forn(i,N)
		forn(j,N){
			above[i][j+1]=above[i][j];
			below[i][j+1]=below[i][j];
			if(coords[j].y>coords[i].y) above[i][j+1]++;
			if(coords[j].y<coords[i].y) below[i][j+1]++;
		}
	for(int i=0; i<N; ++i){
		for(int j=i+1; j<N; ++j){
			int top,bottom;
			if(coords[j].y>coords[i].y){
				top=above[j][j+1]-above[j][i+1];
				bottom=below[i][j+1]-below[i][i+1];
			} else {
				top=above[i][j+1]-above[i][i+1];
				bottom=below[j][j+1]-below[j][i+1];
			} 
			ans += (top+1)*(bottom+1);
		}
	}
	cout << ans+N+1 << nl; 
}

