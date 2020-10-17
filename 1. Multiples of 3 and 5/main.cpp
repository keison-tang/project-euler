/*
Problem 1: Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

/*
    Returns true if numA is a multiple of numB
*/ 
bool isMultiple(int numA, int numB) {
    if ((numA % numB) == 0) {
        return true;
    }
    return false;
}

int main() {
    int sum = 0;

    for (int i = 1; i < 1000; i++) {
        if (isMultiple(i, 3) || (isMultiple(i, 5))) {
            sum += i;
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}