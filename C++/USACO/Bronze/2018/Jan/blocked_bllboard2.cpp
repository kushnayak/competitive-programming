#include <iostream>
#define print_arr(arr, end) do {    \
	cout << "{";                    \
	for (int _=0; _<end; _++){      \
		cout << arr[_];             \
		if (_!=end-1) cout << ", "; \
	}								\
	cout << "}\n"; 					\
} while(0)
#define nl '\n'

using namespace std;


void setIO(string name) { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((name+".in").c_str(), "r", stdin); 
  freopen((name+".out").c_str(), "w", stdout);
}

int X1, Y1, X2, Y2, X3, Y3, X4, Y4;

bool covered(int X, int Y, int X1, int Y1, int X2, int Y2) {
	return (X1 <= X && X <= X2) && (Y1 <= Y && Y <= Y2);
}

void solve() {
	cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;

	int corners = 0;
	if (covered(X1, Y1, X3, Y3, X4, Y4)) corners++;
	if (covered(X2, Y1, X3, Y3, X4, Y4)) corners++;
	if (covered(X1, Y2, X3, Y3, X4, Y4)) corners++;
	if (covered(X2, Y2, X3, Y3, X4, Y4)) corners++;


	if (corners < 2) {
		cout << (Y2 - Y1) * (X2 - X1) << nl;
	} else if (corners == 4) {
		cout << 0 << nl;
	} else {
		int bounded = (min(Y2,Y4) - max(Y1, Y3)) * (min(X2,X4) - max(X1, X3));
		cout << (Y2 - Y1) * (X2 - X1) - bounded << nl;
	}

} 


int main() {
	#ifdef KUSH_LOCAL
		;
	#else 
		setIO("billboard");
	#endif

	solve();
	
}
