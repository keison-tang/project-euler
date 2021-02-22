/*
Problem 85: Counting rectangles

By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

x, y
1, 1 : 6 
2, 1 : 4
3, 1 : 2
1, 2 : 3
2, 2 : 2
3, 2 : 1
= 
18

Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
*/

#include <iostream>

/*
Returns number of rectangles inside a rectangular grid of x by y units. There is a pattern if you list out the number of rectangles for each possible x by y combination.
@param x Rectangle side length x
@param y Rectangle side length y
@returns Number of rectangles
*/
unsigned int numRectangles(unsigned int x, unsigned int y) {
    unsigned int sum = 0, start = 1, loop = 1;

    for (start; start <= x; start++) {
        for (loop = 1; loop <= y; loop++) {
            sum += start * loop;
        }
    }
    
    return sum;
}

int main() {

    int smallestDiff = 2000000, smlX, smlY, res;

    for (int x = 1; x <= 2000; x++) { // 1 x 2000 gives over 2 mil rectangles
        for (int y = 1; y <= 2000; y++) {
            res = numRectangles(x, y);

            res = 2000000 - res; //difference to 2 million
            if (res < 0) res *= -1;

            if (res < smallestDiff) { //update smallest difference
                smallestDiff = res;
                smlX = x;
                smlY = y;
            }

            if (numRectangles(x, y) > 2000000) break;
        }
    }

    std::cout << smlX * smlY << " " << smlX << " " << smlY << " " << smallestDiff << std::endl;

    return 0;
}