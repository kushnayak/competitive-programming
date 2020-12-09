// O(2^n)
#include <iostream>
#include <vector>
using namespace std;



void printArr(vector<int> &a);

vector<int> org = {1,2,3,4,5,6,7,8,9,10};
int N = org.size();

void search(vector<int> &org, vector<int> &sub, int i) {
	if (i == N) {
		printArr(sub);
	} else {
		sub.push_back(org[i]);
		search(org, sub, i+1);
		sub.pop_back();
		search(org, sub, i+1);
	}
}


int main() {

	vector<int> sub;
	search(org, sub, 0);
}
void printArr(vector<int> &a) {
	for (int i: a)
		cout << i << " ";
	cout << "\n";
}