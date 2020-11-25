#include <bits/stdc++.h>
using namespace std;

#define cin fin 
#define cout fout

ifstream fin("word.in");
ofstream fout("word.out");

int N, K;
string words[101];

int main() {
	
	cin >> N >> K;
	for (int i=0; i<N; i++)
		cin >> words[i];

	string s = " ";

	int used = 0;
	for (int i=0; i<N; i++) {
		string str = words[i];
		used += str.length();

		if (used <= K) {
			if (used - str.length() != 0)
				cout << " ";
			cout << str;
		} else {
			used = str.length();
			cout << "\n" << str;
		}
	}
}
