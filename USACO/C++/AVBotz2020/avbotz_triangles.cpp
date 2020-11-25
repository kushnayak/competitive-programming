#include <iostream>
#include <fstream>
#include <cmath>
#define FOR(var,b) for (int var=0; var<b; ++var)
using namespace std;

int n, X[100], Y[100];

int solve() {
	double sum = 0;

	FOR(i,n) {
		FOR(j,n) {
			if (i==j)
				continue;
			FOR(k,n){
				if (i==k||j==k)
					continue;
				if (X[i]==X[j] && Y[i]==Y[k])
					sum += abs(Y[i]-Y[j]) + abs(X[i]-X[k]) + hypot(Y[i]-Y[j],X[i]-X[k]);
			}
		}
	}
	return round(sum);
}




int main() {
	
	ifstream fin("test1.in");
	fin >> n;
	FOR(i,n) {
		fin >> X[i];
		fin.ignore(1);
		fin >> Y[i];
	}
	cout << solve() << "\n";
}






