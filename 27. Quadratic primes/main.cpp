/*
Problem 27: Quadratic primes

Euler discovered the remarkable quadratic formula: n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39.

The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values 0 <= n <= 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form: n^2 + an + b, where mod(a) < 1000 mod(b) <= 1000 

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include <iostream>

#include <cmath>

/*
    Returns true if the number is a prime number
*/
bool IsPrime(int number) {
    if (number <= 3) {
        return (number > 1);   // 2 and 3 is prime
    } else if (((number % 2) == 0) || ((number % 3) == 0)) {
        return false;   // divisible by 2 or 3 not primes
    }

    int i = 5;

    while ((i * i) <= number) {
        if (((number % i) == 0) || ((number % (i + 2)) == 0)) {
            return false;
        }
        i += 6;
    }

    return true;
}

/*
Finds number of consecutive primes for quadratic expression: n^2 + an + b
@param a Coefficient a
@param b Coefficient b
@return Number of consecutive primes starting with n = 0;
*/
int ConsecutivePrimes(int a, int b) {
    int n = 0, count = 0;

    while(1) {
        int ans = pow(n, 2) + (a * n) + b;

        if (IsPrime(ans)) {
            count++;
        } else {
            break;
        }

        n++;
    }
    
    return count;
}

int main() {
    int maxA = 0, maxB = 0, maxPrimes = 0;

    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            if (ConsecutivePrimes(a, b) > maxPrimes) {
                maxA = a;
                maxB = b;
                maxPrimes = ConsecutivePrimes(a, b);
            }
        }
    }

    std::cout << maxA << " " << maxB << " " << maxPrimes << std::endl;
    std::cout << maxA * maxB << std::endl;

    return 0;
}