/*
Problem 49: Prime permutations

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <iostream>
#include <algorithm>
#include <string>

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
    Returns true if two input numbers are permutations of each other
*/
bool IsPerm(int a, int b) {
    std::string strA, strB;

    strA = std::to_string(a);
    strB = std::to_string(b);

    std::sort(strA.begin(), strA.end());
    std::sort(strB.begin(), strB.end());

    return (strA == strB);
}

int main() {
    for (int i = 1000; i < 10000; i++) {    //search 4 digit numbers
        if (IsPrime(i)) {
            for (int j = 1; j < 10000; j++) {   //search value to increase by
                int n2 = i + j;
                int n3 = i + j + j;

                if (IsPrime(i) && IsPrime(n2) && IsPrime(n3) 
                && IsPerm(i, n2) && IsPerm(n2, n3)) {
                    std::cout << i << " " << n2 << " " << n3 << std::endl;  
                }
            }
        }
    }

    return 0;
}