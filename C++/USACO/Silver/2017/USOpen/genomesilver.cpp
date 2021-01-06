#include <iostream>
#include <fstream>


using namespace std;

int n, m;
int spot_base[500][50], no_spot_base[500][50], track[64];

bool valid(int pos1, int pos2, int pos3) {
    bool ok = true;
    for (int i=0; i<n; i++)
        track[16 * spot_base[i][pos1] + 4 * spot_base[i][pos2] + spot_base[i][pos3]] = 1;
    for (int i=0; i<n; i++)
        if(track[16 * no_spot_base[i][pos1] + 4 * no_spot_base[i][pos2] + no_spot_base[i][pos3]])
            ok =  false;
    for (int i=0; i<n; i++)
        track[16 * spot_base[i][pos1] + 4 * spot_base[i][pos2] + spot_base[i][pos3]] = 0;
    return ok;

}
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    fin >> n >> m;

    for (int i=0; i<n; i++) {
        string s; fin >> s;
        for(int j=0; j<m; j++) {
            char c = s[j];
            if (c=='A') no_spot_base[i][j] = 0;
            if (c=='C') no_spot_base[i][j] = 1;
            if (c=='G') no_spot_base[i][j] = 2;
            if (c=='T') no_spot_base[i][j] = 3;
        }
    }
    for (int i=0; i<n; i++) {
        string s; fin >> s;
        for(int j=0; j<m; j++) {
            char c = s[j];
            if (c=='A') spot_base[i][j] = 0;
            if (c=='C') spot_base[i][j] = 1;
            if (c=='G') spot_base[i][j] = 2;
            if (c=='T') spot_base[i][j] = 3;
        }
    }

    int ans = 0;
    for (int i=0; i<m; i++)
        for (int j = i + 1; j < m; j++)
            for (int k = j + 1; k < m; k++)
                if (valid(i, j, k))
                    ans++;

    fout << ans << endl;
} 
