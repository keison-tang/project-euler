/*
Problem 97: Large non-Mersenne prime

The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593 − 1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433 × 2^7830457 + 1.

Find the last ten digits of this prime number.
*/

/*
Returns last 10 digits of a number i.e anything past the billions place value is cut off
@param num A number to truncate to last 10 digits
@returns Last 10 digits of a number
*/
long long TruncTenDigit(long long num) {
    return num % 10000000000;   //remainder of division by 10 billion
}

#include <iostream>

int main() {
    //since we only care about last 10 digits we compute 2^7830457 but just truncate result to 10 digits
    
    long long result = 2;

    for (int i = 1; i < 7830457; i++) {
        result = TruncTenDigit(2 * result);
    }

    result = TruncTenDigit(28433 * result + 1);

    std::cout << result << std::endl;

    return 0;
}