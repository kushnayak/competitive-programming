#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

#define FOR(i,n) for (int i=0; i<n; i++)
const int INF = INT32_MAX;

int n, channel[100][100];


int main() {
	ifstream fin("Image.in");
	int n; fin >> n;
	int minPixel = INF, maxPixel = 0;
	FOR (i, n) {
		FOR(j, n) {
			int pixel; fin >> pixel;
			channel[i][j] = pixel;
			minPixel = min(minPixel, pixel);
			maxPixel = max(maxPixel, pixel);
			if (j!=n-1)
			
				fin.ignore(1);
		}
	}
 		

	int diff = maxPixel-minPixel;
	
	FOR(i,n) {
		
		string line = "";
		FOR(j,n) {
			if (!(diff<10))
				if (channel[i][j]<100)
					channel[i][j] += round(diff * .1);
			line += channel[i][j];
			line += (j!=n-1) ?  ";" : "";
		}
		cout << line << endl;
	}
}





