#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y;
    fin >> x >> y;
    int total_distance = 0;
    int cur_pos = x;
    int to = 0;
    int change = 1;
    while (true) {
        to = x + change;
        if ((to >= y && y > x) || (to <= y && y < x)) {
            total_distance += abs(cur_pos - y);
            break;
        }
        total_distance += abs(to - cur_pos);
        cur_pos = to;
        change *= -2;
    }
    fout << total_distance << endl;

} 
