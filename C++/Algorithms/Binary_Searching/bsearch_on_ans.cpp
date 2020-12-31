// O(logn)
#include <iostream>
#define nl '\n'
using namespace std;

/*function should be montonic, {false, false, false, true, true, true} 
or {true, true, true, false, false, false}*/

/*check function which tells us whether some value works in the function
this function looks like {true, true, true, false, false, false}
we want to find max value such that check is true */
bool check(int k) {
	return k <= 30;
}


/*bsearch implementation which uses jumps to determine the ans
check https://www.topcoder.com/binary-stride-a-variant-on-binary-search/ for more detail
*/
int search() {
	int pos = 0, max = 40; //[pos,max] is the range of our ans
	for(int a=max; a>=1; a/=2) {
		while(check(pos+a)) pos += a; 
		//find the max true value, can replace with !check() to find max false and return pos+1 for min true
	}
	return pos;
}
int main() {
	cout << search() << nl;
}