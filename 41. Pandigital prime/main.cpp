/*
Problem 41: Pandigital prime

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include <string>
#include <algorithm>

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
    Returns true if the input number is pandigital
*/
bool IsPandigital(int num) {
    std::string str = std::to_string(num);
    std::sort(str.begin(), str.end());

    // check sorted digits are equal to 1 to length
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] - '0') != (i + 1)) {    
            return false;
        }
    }

    return true;
}

int main() {
    unsigned long long largest = 0, i;

    /*
    Using divisibility rules: 
    A number is divisible by 3 if the sum of digits can be divided by 3
    If a number is divisible by 3 it can't be prime
    Sum of 1-9 = 45, % 3 = 0
    Sum of 1-8 = 36, % 3 = 0
    Therefore max pandigital prime consists of digits 1-7
    */
    for (i = 7654321; i > 0; i -= 2) {
        if (IsPandigital(i)) {
            if (IsPrime(i)) {
                largest = i;
                break;
            }
        }
    }

    std::cout << largest << std::endl;

    return 0;
}