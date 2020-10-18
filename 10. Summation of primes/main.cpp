/* 
Problem 10: Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <iostream>

/*
    Returns true if the number is a prime number
*/
bool isPrime(int number) {
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

int main() {
    int MAX = 2000000;    
    
    unsigned long long sum = 0;

    for (unsigned long long i = 0; i < MAX; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    std::cout << "Sum of all primes below " << MAX << " is: " << sum << std::endl;

    return 0;
}