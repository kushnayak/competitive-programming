#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;


int rate_change[MAX + 1][3];
int rate_day[MAX + 1][3];
bool highest[MAX + 1][3];
int ans = 0;

void highest_updater(int day) {
    int day_highest = max(max(rate_day[day][0], rate_day[day][1]), rate_day[day][2]);
    for (int i = 0; i < 3; i++) {
        if (rate_day[day][i] == day_highest) highest[day][i] = true;
    }
}
void diff_board(int day) {
    highest_updater(day);
    highest_updater(day - 1);
    for (int i = 0; i < 3; i++) {
        if (highest[day - 1][i] != highest[day][i]) {
            ans++;
            return;
        }
    }
}

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int N, day, change, index;
    string cow;
    fin >> N;
    for (int i=0; i<N; i++) {
        fin >> day >> cow >> change;
        if (cow == "Bessie") index = 0;
        else if (cow == "Elsie") index = 1;
        else if (cow == "Mildred") index = 2;
        rate_change[day][index] = change;
    }
    for (int i=0; i<3; i++) {
        rate_day[0][i] = 7;
    }
    for (int i=1; i<=100; i++) {
        for (int j=0; j<3; j++)
            rate_day[i][j] = rate_change[i][j] + rate_day[i-1][j];
    }

    for (int i = 1; i <= 100; i++) {
        diff_board(i);
    }
    fout << ans << endl;
    fout.close();
//    for (int i = 0; i < 100; i++){
//        for (int j = 0; j<3; j++)
//                cout << highest[i][j] << " ";
//        cout << endl;
//    }



}