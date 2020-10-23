/*
Problem 14: Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

FYI: int doesn't cut it for assigning n. Need to use long. Was wondering why my run time was so bad and turns out n overflowed when using int
*/

#include <iostream>

/*
    Returns n number in Collatz sequence for an odd number
    @param n Odd number
    @return n number in sequence
*/
long oddFn(long n) {
    return (3 * n) + 1;
}

/*
    Returns n number in Collatz sequence for an even number
    @param n Even number
    @return n number in sequence
*/
long evenFn(long n) {
    return n/2;
}

int main() {
    long largest = 0;
    int largestChainLen = 0;

    for (int i = 1000000; i > 0; i--) {
        int chainLen = 1;
        long n = i;

        while (n != 1) {
            if (n % 2) {
                n = oddFn(n);
            } else {
                n = evenFn(n);
            }

            chainLen++;
        }

        if (chainLen > largestChainLen) {
            largest = i;
            largestChainLen = chainLen;
        }
    }

    std::cout << largest << " " << largestChainLen << std::endl;

    return 0;
}