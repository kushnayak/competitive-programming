#include <iostream>
#include <fstream>
#define A 65
#define Z 90
#define N 52
using namespace std;

string circle;

bool valid(int lett1, int lett2) {
    char first = char(lett1), second = char(lett2);
    int first_from = -1, first_to = -1;
    int second_from = -1, second_to = -1;
    for (int i=0; i<N; i++) {
        if (circle[i]==first) {
            if (first_from==-1)
                first_from = i;
            else
                first_to = i;
        }
        if (circle[i]==second) {
            if (second_from==-1)
                second_from = i;
            else
                second_to = i;
        }
    }

    if ((first_from < second_from && second_from < first_to) &&
    (second_from < first_to && first_to < second_to))
        return true;

    return false;
}
int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    fin >> circle;
    int ans = 0;
    for (int i=A; i<=Z; i++) {
        for (int j=A; j<=Z; j++) {
            if (i==j)
                continue;
            if (valid(i, j)) {
                cout << char(i) << " "<< char(j) << endl;
                cout << endl;
                ans++;
            }
        }
    }
    fout << ans;
} 
