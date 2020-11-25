#include <iostream>
#include <fstream>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");
int N, A[101];

int main() {
    
    cin >> N;
    for (int i=0; i<N; i++) 
        cin >> A[i];

    int ans = 0;
    for (int i=N-1; i>=1; i--) {
        if (A[i] > A[i-1]) {
            ;
        }
        else {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;

}
