/* 
Problem 7: 10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
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
    int targetPrimeIndex = 10001;
    
    int primeCount = 0;
    int targetPrimeNum = 0;
    int i = 0;

    while (primeCount != targetPrimeIndex) {
        if (isPrime(i)) {
            primeCount++;
            targetPrimeNum = i;
        }

        i++;
    }

    std::cout << "The " << targetPrimeIndex << " prime number is: " << targetPrimeNum << std::endl; 

    return 0;
}