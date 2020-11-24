/*
Problem 32: Pandigital products

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

bool IsPandigital(int a, int b, int c) {
    std::string str = std::to_string(a) + std::to_string(b) + std::to_string(c);
    std::sort(str.begin(), str.end());

    return (str == "123456789");
}

int main() {
    int sum = 0;
    std::set<int> products;

    // max 2 digits x max 4 digits = max 5 digit
    for (int i = 1; i <= 99; i++) {
        for (int j = 1; j <= 9999; j++) {
            if (IsPandigital(i, j, (i * j))) {
                products.insert(i * j);
                //std::cout << i << " " << j << std::endl;
            }
        }
    }

    for (std::set<int>::iterator it = products.begin(); it != products.end(); it++) {
        sum += *it;
    }

    std::cout << sum << std::endl;
}