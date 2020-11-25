#include <iostream>
#include <fstream>
#define RANGE 1001
using namespace std;

int n;
int intervals[100][2];

int time(int skip) {
    int shift[RANGE]={0};
    for (int i=0; i<n; i++)
        if (i!=skip)
            for (int j=intervals[i][0]; j<intervals[i][1]; j++)
                shift[j] = 1;
    int total = 0;
    for (int i=1; i<RANGE; i++)
        if (shift[i])
            total++;
    return total;
}
int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    fin >> n;
    for (int i=0; i<n; i++) {
        fin >> intervals[i][0] >> intervals[i][1];
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, time(i));
    }
    fout << ans;
} 
