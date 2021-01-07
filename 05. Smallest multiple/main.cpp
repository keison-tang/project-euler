/*
Problem 5: Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>

int main() {
    int lastNumInRange = 20;
    
    int smallestMultiple = 0;
    int i = 1;

    while (smallestMultiple == 0) {
        for (int j = 1; j <= lastNumInRange; j++) {
            if ((i % j) != 0) { // not evenly divisible
                break;  // skip to next i to check
            } else {    // evenly divisible
                if (j == lastNumInRange) {  // evenly divisible by all numbers from 1 to lastNumInRange
                    smallestMultiple = i;
                }
                continue;
            }
        }
        i++;
    }

    std::cout << "Smallest multiple: " << smallestMultiple << std::endl;

    return 0;
}