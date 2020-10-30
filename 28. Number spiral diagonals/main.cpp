/*
Problem 28: Number spiral diagonals

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

FYI: originally was going to make an array but there's a less memory intensive algorithm method
*/

#include <iostream>

#define SPIRAL_SIZE 1001   //has to be an odd number

int main() {
    unsigned int ring = 1, numsPerRing = 1, ringStartNum = 1, ringSideLen = 1, sum = 1;

    while (ring < ((SPIRAL_SIZE / 2) + 1)) {
        // next ring
        ring++;
        ringSideLen = (ring * 2) - 1;
        numsPerRing = (ring - 1) * 8;   //increases by 8 when going to next ring
        ringStartNum = (ringSideLen * ringSideLen) - numsPerRing + 1; //end ring num is related to square of ring len

        //std::cout << ring << " : " << ringStartNum << std::endl;

        // sum the four corners
        unsigned int br, bl, tl, tr;
        br = ringStartNum + ringSideLen - 2;
        bl = br + ringSideLen - 1;
        tl = bl + ringSideLen - 1;
        tr = tl + ringSideLen - 1;

        //std::cout << ring << " : " << br << " " << bl << " " << tl << " " << tr << std::endl;

        sum += br + bl + tl + tr;
    }

    std::cout << sum << std::endl;

    return 0;
}