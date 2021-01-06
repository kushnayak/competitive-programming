#include <iostream>
#include <cstdio>
#include <cmath>
#include <cfloat>
#define IO(f) cin.tie(0)->sync_with_stdio(0); if(fopen(f ".in", "r")) freopen(f ".in","r",stdin)
#define forn(i,N) for(int i=0; i<N; i++)
#define nl '\n'
using namespace std;
using tp = tuple<double,double,double>;

int N;
tp p[10];
const tp origin={0,0,0};
double ans=DBL_MAX;

double dist(const tp& a, const tp& b) {return sqrt(pow(get<0>(a)-get<0>(b),2)+pow(get<1>(a)-get<1>(b),2)+pow(get<2>(a)-get<2>(b),2));}
double query(){double sum=dist(origin,p[0]); forn(i,N-1) sum+=dist(p[i],p[i+1]); return sum; }

int main(){
	IO("mission");
	cin >> N;
	forn(i,N){ double x,y,z; cin >> x >> y >> z; p[i]={x,y,z}; }
	cout << round(query());
	sort(p,p+N);
	do{ ans = min(ans,query()); } while(next_permutation(p,p+N));
	cout << " " << round(ans) << nl;
}