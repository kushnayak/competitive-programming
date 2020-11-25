#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#define FOR(i, a, b) for (int i=a;i<b;i++)
#define pb(x) push_back(x)
using namespace std;
using vi = vector<int>;


set<int> milks;


void friday(int milk, vi buckets_1, vi buckets_2) {
    FOR (i, 0, 10) {
        int remove = buckets_2[i];
        milks.insert(milk+remove);
    }
}
void thursday(int milk, vi buckets_1, vi buckets_2) {
    FOR (i, 0, 10) {
        int remove = buckets_1[i];
        vi new_b1 = buckets_1, new_b2 = buckets_2;
        new_b1.erase(new_b1.begin() + i);
        new_b2.pb(remove);
        friday(milk-remove, new_b1, new_b2);
    }
}
void wednesday(int milk, vi buckets_1, vi buckets_2) {
    FOR (i, 0, 10) {
        int remove = buckets_2[i];
        vi new_b1 = buckets_1, new_b2 = buckets_2;
        new_b2.erase(new_b2.begin() + i);
        new_b1.pb(remove);
        thursday(milk+remove, new_b1, new_b2);
    }
}
void tuesday(int milk, vi buckets_1, vi buckets_2) {
    FOR (i, 0, 10) {
        int remove = buckets_1[i];
        vi new_b1 = buckets_1, new_b2 = buckets_2;
        new_b1.erase(new_b1.begin() + i);
        new_b2.pb(remove);
        wednesday(milk-remove, new_b1, new_b2);
    }
}
int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    vi buckets_1, buckets_2;

    FOR (i, 0, 10) {
        int n; fin >> n;
        buckets_1.pb(n);
    }
    FOR (i, 0, 10) {
        int n; fin >> n;
        buckets_2.pb(n);
    }

    tuesday(1000, buckets_1, buckets_2);

    fout << milks.size() << "\n";

} 
