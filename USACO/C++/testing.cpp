#include <bits/stdc++.h>
#define IO(😵) cin.tie(0)->sync_with_stdio(0); if (fopen(😵 ".in", "r")) freopen(😵 ".in","r",stdin), freopen(😵 ".out","w",stdout)
#define FOR(😂,😀) for(int 😂=0; 😂<😀; 😂++) 

using namespace std;

int 🥰, 🥺[100], 👹[100];
int main() {
	IO("triangles");
	cin >> 🥰;
	FOR(💩, 🥰)
		 cin >> 🥺[💩] >> 👹[💩];
	cout << 🥰 << endl;
	int 😎 = 0;
	FOR(💩, 🥰) {
		FOR(🤓, 🥰) {
			FOR(🙄, 🥰) {
				if (💩==🤓||💩==🙄||🤓==🙄) continue;
				if (🥺[💩]==🥺[🤓]&&👹[💩]==👹[🙄])
					😎 = max(😎, abs(👹[💩]-👹[🤓])*abs(🥺[💩]-🥺[🙄]));
			}
		}
	}
	cout << 😎 << endl;

}
