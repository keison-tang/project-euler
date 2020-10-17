/*
Problem 3: Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

FYI: 
Had to use long long data types as the number was so large. 
Implements primality test pseudocode from Wikipedia. 
*/

#include <iostream>
#include <math.h>

/*
    Returns true if number is even
*/
bool isEven(long long number) {
    if ((number % 2) == 0) {
        return true;
    }
    return false;
}

/*
    Returns true if numA is a factor of numB
*/
bool isFactor(long long numA, long long numB) {
    if ((numB % numA) == 0){
        return true;
    }
    
    return false;
}

/*
    Returns true if the number is a prime number
*/
bool isPrime(long long number) {
    if (number <= 3) {
        return (number > 1);   // 2 and 3 is prime
    } else if ((isEven(number)) || (isFactor(3, number))) {
        return false;   // divisible by 2 or 3 not primes
    }

    long long i = 5;

    while ((i * i) <= number) {
        if (((number % i) == 0) || ((number % (i + 2)) == 0)) {
            return false;
        }
        i += 6;
    }

    return true;
}


int main() {
    long long THE_NUMBER = 600851475143;
    long long largestPrimeFactor = 0;

    for (long long i = 1; i <= std::sqrt(THE_NUMBER); i++) { // only need to check up to sqrt of the target
        // check if factor first, as there are less factors than primes = faster execution
        if (isFactor(i, THE_NUMBER)) {
            if (isPrime(i)){
                std::cout << i << " is a prime factor of " << THE_NUMBER << std::endl;
                largestPrimeFactor = i;
            } else {
                continue;
            }
        } else {
            continue;
        }
    }

    std::cout << "Largest prime factor of " << THE_NUMBER << " is " << largestPrimeFactor << std::endl;

    return 0;
}