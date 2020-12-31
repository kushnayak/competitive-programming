#include <bits/stdc++.h>
#define nl '\n'
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

int nums[7];

bool valid() {
	int a = nums[0], b = nums[1], c = nums[2];
	if (nums[3]==a+b && nums[4]==b+c && nums[5]==c+a && nums[6]==a+b+c) return true;
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	forn(i,7) cin >> nums[i];
	sort(nums, nums+7);
	do {
		if (valid()){
			cout << nums[0] << " " << nums[1] << " " << nums[2] << nl;
			break;
		}
	} while(next_permutation(nums, nums+7));
}
