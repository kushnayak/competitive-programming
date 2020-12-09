#include <iostream>
#include <string>
#define rep(i, a, b) for (int i=a; i<b; i++)
using namespace std;

char A[8][8];
int c = 0;


bool isValid(int row, int col) {

    if (A[row][col] == '*' ) 
        return false;

    // check columns
    for (int i=0; i<row; i++) 
        if (A[i][col] == 'q')
            return false;

    // check negative diagonal
    for (int i=row, j=col; i >= 0 && j >= 0; i--, j--) 
        if (A[i][j] == 'q')
            return false;
    // check positive diagonal

    for (int i=row, j=col; i >=0 && j < 8; i--, j++)
        if (A[i][j] == 'q')
            return false;
    return true;

    
} 
void search(int row) {
    if (row == 8) {
        c++;
        return;
    }
    for (int col=0; col<8; col++) {
        if (isValid(row, col)) {
            A[row][col] = 'q';
            search(row+1);
            A[row][col] = '.';
        }
    }

}
void solve() {
    rep (i, 0, 8)
        rep (j, 0, 8)
            cin >> A[i][j];
    search(0);
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
