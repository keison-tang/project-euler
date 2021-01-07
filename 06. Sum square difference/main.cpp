/*
Problem 6: Sum square difference

The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 ... 10^2 = 385

The square of the sum of the first ten natural numbers is, (1 + 2 ... + 10)^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <math.h>

int main() {
    int howManyNum = 100;

    int sumOfSquares = 0;
    int squareOfSum = 0;
    int sumOfNum = 0;
    int difference = 0;

    for (int i = 1; i <= howManyNum; i++) {
        sumOfSquares += std::pow(i, 2);

        sumOfNum += i;
    }

    squareOfSum = std::pow(sumOfNum, 2);

    difference = squareOfSum - sumOfSquares;

    std::cout << "Difference between sum of squares of first " << howManyNum << " natural numbers and square of sum: " << squareOfSum << " - " << sumOfSquares << " = " << difference << std::endl;

    return 0;
}