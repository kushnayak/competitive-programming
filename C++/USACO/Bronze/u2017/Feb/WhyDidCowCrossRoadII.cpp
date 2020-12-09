#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {

    cout << gcd(1000, 100) << endl;

}

