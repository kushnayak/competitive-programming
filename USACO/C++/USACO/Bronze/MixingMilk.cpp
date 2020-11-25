#include <fstream>
using namespace std;

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int capacity[3];
    int amount[3];
    for (int i = 0; i < 3; i++) {
        fin >> capacity[i];
        fin >> amount[i];
    }
    for (int i = 0; i < 100; i++) {
        int from = i % 3;
        int to = (from + 1 == 3) ? 0: from + 1;
        int pouring = min(amount[from], capacity[to] - amount[to]);
        amount[from] -= pouring;
        amount[to] += pouring;
    }
    for (int i: amount) {
        fout << i << endl;
    }
    fout.close();
}
