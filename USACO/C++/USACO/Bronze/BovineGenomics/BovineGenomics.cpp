#include <iostream>
#include <fstream>

using namespace std;

int n,m;
string spot[100];
string not_spot[100];

bool valid(int col) {
    for (int i=0; i<n; i++) {
        char spot_gene = spot[i][col];
        for (int j=0; j<n; j++)
            if (not_spot[j][col]==spot_gene)
                return false;
    }
    return true;
}
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    fin >> n  >> m;
    for (int i=0; i<n; i++)
        fin >> spot[i];
    for (int i=0; i<n; i++)
        fin >> not_spot[i];
    int total = 0;
    for (int i=0; i<m; i++)
        if (valid(i))
            total++;
    fout << total << endl;

} 
