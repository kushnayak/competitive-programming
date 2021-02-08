#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
using namespace std;
vector<string> v;
string s;

int main() {
	cin >> s;
	sort(all(s));
	do{ v.push_back(s); } while(next_permutation(all(s)));
	cout << v.size() << '\n';
	for(auto u: v) cout << u << '\n';
}

