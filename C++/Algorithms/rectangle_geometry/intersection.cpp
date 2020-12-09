//https://www.coursera.org/lecture/writing-running-fixing-code/intersection-of-two-rectangles-Izza8
//algorithm given 2 overlapping xy axis-parallel rectangles returns the area 
// of intersection between them 

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

//(x1, y1) (x2, y2) are respectively the bottom left and top right corners of rect1 
// rect2 same thing for x3 x4
int intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int left = max(x1, x3); 
	int right = min(x2, x4);
	int bottom = max(y1, y3);
	int top = min(y2, y4);
	//if this condition is true the rectangles do not overlap
	if (right - left < 0 || top - bottom < 0) {
		return 0;
	}

	return (left - right) * (top - bottom);
}
int main() {

	cout << intersection(2, 2, 4 ,4, 1 ,1 ,3 ,5) << endl;
	
}
