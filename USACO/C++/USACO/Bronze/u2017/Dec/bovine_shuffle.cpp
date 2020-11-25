#include <bits/stdc++.h>
using namespace std;

int N, shuff[100];
string id[100];

void setIO(string name = "") { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  if((name).size()){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
  }
}


int main() {
	setIO("shuffle");

	cin >> N;
	for (int i=0; i<N; i++)
		cin >> shuff[i];
	for (int i=0; i<N; i++)
		cin >> id[i];

	for (int i=0; i<3; i++) {
		string temp[100];
		for (int j=0; j<N; j++) {
			temp[j] = id[shuff[j]-1];
		}
		for (int j=0; j<N; j++)
			id[j] = temp[j];
	}

	for (int i=0; i<N; i++)
		cout << id[i] << "\n";

}
