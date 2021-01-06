#include <bits/stdc++.h>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if (fopen(f ".in", "r")) freopen(f ".in","r",stdin), freopen(f ".out","w",stdout)
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxN = 1e5;
const int maxP = 1e9+1;
int N, x[maxN], y[maxN], p[maxN], minl[maxN], maxr[maxN];

/*
solution:
idk this is pretty hard check editorial 
We can represent particles that can interact with each other as vertices with an edge
To find the minimum particles left, we must find how many connected components 
exist on the graph, but O(N^2) is too slow, so we need to sort
Now we have to find min from the left and max from the right and if 
min[i] > max[i+1] that means the point has greater x, but not high enough y to 
encompass the minimum previous y value, and therefore be a part of the component so we 
add one to the components 
complexity: O(nlogn + n)
*/
bool cmp(const int a, const int b) {
	if (x[a]==x[b]) return y[a] < y[b];
	return x[a] < x[b];
}

int main() {
	IO("moop");
	cin >> N;
	forn(i,N)
		cin >> x[i] >> y[i], p[i] = i;
	sort(p,p+N,cmp);

	int mn = maxP, mx = -maxP;

	for (int i=0; i<N; i++) 
		minl[i] = min(mn, y[p[i]]), mn=min(mn, y[p[i]]);
	for (int i=N-1; i>=0; i--)
		maxr[i] = max(mx, y[p[i]]), mx = max(mx, y[p[i]]);

	int components = 1;
	forn(i,N-1) 
		if (minl[i] > maxr[i+1])
			components++;

	cout << components << nl;
}
