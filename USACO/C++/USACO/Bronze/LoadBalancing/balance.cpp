#include <iostream>
#include <fstream>

using namespace std;

int n, b, X[100], Y[100];

int max_region(int x_coord, int y_coord) {
    int x = X[x_coord]+1; //vertical
    int y = Y[y_coord]+1; //horizontal
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (int i=0; i<n; i++) {
        if (X[i] > x && Y[i] > y) q1++;
        if (X[i] < x && Y[i] > y) q2++;
        if (X[i] < x && Y[i] < y) q3++;
        if (X[i] > x && Y[i] < y) q4++;
    }
    return max(max(q1,q2),max(q3,q4));
}
int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    fin >> n >> b;


    for (int i=0; i<n; i++)
        fin >> X[i] >> Y[i];

    int ans = INT32_MAX;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            ans = min(ans, max_region(i, j));

    fout << ans << endl;
} 
