/*
Problem 53: Combinatoric selections

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 
.

In general, 
 
, where , , and .

It is not until , that a value exceeds one-million: 
.

How many, not necessarily distinct, values of 
 for , are greater than one-million?
*/

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

boost::multiprecision::uint1024_t Factorial(int n) {
    boost::multiprecision::uint1024_t result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

boost::multiprecision::uint1024_t Combination(int n, int r) {
    return Factorial(n) / (Factorial(r) * Factorial(n-r));
}

int main() {

    int count = 0;

    for (int n = 1; n <= 100; n++) {
        for (int r = 1; r < n; r++) {
            if (Combination(n, r) > 1000000) count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}