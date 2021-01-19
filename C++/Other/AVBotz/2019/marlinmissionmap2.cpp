#include <iostream>
#include <cstdio>
#include <cmath>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if(fopen(f ".in", "r")) freopen(f ".in","r",stdin)
#define forn(i,N) for(int i=0; i<(N); i++)
#define x first.first
#define y first.second
#define z second
using namespace std;
using ppi = pair<pair<int,int>,int>;

int N;
ppi p[10];
const ppi origin={{0,0},0};
double ans=1.797e308;
double dist(const ppi& a, const ppi& b){ return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2)); }
double query(){ double sum=dist(origin,p[0]); forn(i,N-1) sum+=dist(p[i],p[i+1]); return sum; }

int main(){
	IO("mission");
	cin >> N; forn(i,N) cin >> p[i].x >> p[i].y >> p[i].z;
	cout << round(query()) << ' ';
	sort(p,p+N); do{ ans=min(ans,query()); } while(next_permutation(p,p+N));
	cout << round(ans) << '\n';
}