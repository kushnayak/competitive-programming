#include <bits/stdc++.h>
#define print_arr(arr, end) do { cout << "{"; for (int _=0; _<end; _++){ cout << arr[_]; if (_!=end-1) cout << ", "; } cout << "}\n"; } while(0)
#define nl '\n'

using namespace std;


void setIO(string name) {
	#ifdef KUSH_LOCAL
		;
	#else 
		ios_base::sync_with_stdio(0); cin.tie(0); 
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	#endif
}

int N, K, a1, a2, b1, b2;

int cow[100];

void rev(int a, int b) {
	int l = a-1, r = b-1;
	while (l <= r) {
		swap(cow[l], cow[r]);
		l++; r--;
	} 
}

bool orginal() {
	for (int i=0; i<N; i++)
		if (cow[i] != i+1)
			return false;
	return true;
}

int main() {

	// kinda weird how they expect people to find a cycle in swaps 
	// but the highest number of K needed to reach a cycle for N≤100 
	// is like 26,460 which can be found swapping (0,98), (1, 99) until original is found

	setIO("swap");
	
	cin >> N >> K >> a1 >> a2 >> b1 >> b2;

	for (int i=0; i<N; i++)
		cow[i] = i+1;

	int cycle = 0;

	do {
		rev(a1, a2);
		rev(b1, b2);
		cycle++;
	} while (!orginal());
	
	for (int i=0; i<N; i++)
		cow[i] = i+1;

	for (int i=0; i<K%cycle; i++) {
		rev(a1, a2);
		rev(b1, b2);
	}
	// cout << "k and cycle are " << K << " " << cycle << nl;
	for (int i=0; i<N; i++) 
		cout << cow[i] << nl;
}




