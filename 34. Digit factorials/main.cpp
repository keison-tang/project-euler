/*
Problem 34: Digit factorials

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>

/*
    Returns n!
*/
int Factorial(int n) {
    int prod = 1;

    for (int i = 1; i <= n; i++) {
        prod *= i;
    }

    return prod;
}

int main() {
    int sum = 0;

    for (int i = 3; i < 9999999; i++) { //7*9! < 9999999, 6*9! !< 999999
        int tmp = i, sumFac = 0;

        // sum each digit factorial
        while (tmp != 0) {
            sumFac += Factorial(tmp % 10);
            
            tmp /= 10;
        }

        if (sumFac == i) {
            std::cout << i << std::endl;
            sum += i;
        }

    }

    std::cout << "sum : " << sum << std::endl;

    return 0;
}