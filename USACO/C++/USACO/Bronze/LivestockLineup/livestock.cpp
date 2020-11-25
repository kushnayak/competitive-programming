#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> line;
vector<string> beside_a, beside_b;
int N;

int where(string a) {
    for (int i=0; i<8; i++)
        if (line[i] == a)
            return i;
    return -1;
}
bool valid() {
    for (int i=0; i<N; i++) {
        if (abs(where(beside_a[i]) - where(beside_b[i])) != 1)
            return false;
    }
    return true;
}

void solve() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    line.push_back("Beatrice");
    line.push_back("Belinda");
    line.push_back("Bella");
    line.push_back("Bessie");
    line.push_back("Betsy");
    line.push_back("Blue");
    line.push_back("Buttercup");
    line.push_back("Sue");

    fin >> N;

    for (int i=0; i<N; i++) {
        string a, b, t;
        fin >> a;
        fin >> t;
        fin >> t;
        fin >> t;
        fin >> t;
        fin >> b;
        beside_a.push_back(a);
        beside_b.push_back(b);
    }


    do {
        if (valid()) {
            for (int i=0; i<8; i++)
                fout << line[i] << "\n";
            break;
        }
    } while (next_permutation(line.begin(), line.end()));

}
int main() {
	solve();
}