/*
Problem 9: Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <math.h>

/*
    Checks if a set of 3 natural numbers (a < b < c) is a pythagorean triplet
    @param a First number
    @param b Second number
    @param c Third number
    @return true if the 3 numbers are a pythagorean triplet, else false
*/
bool isPyTriplet(int a, int b, int c) {
    if ((a < b) && (b < c)) {
        if ((std::pow(a, 2) + std::pow(b, 2)) == std::pow(c, 2) ) {
            return true;
        }
    }

    return false;
}


int main() {
    int a = 0;
    int b = 0;
    int c = 0;

    //brute force
    for (int i = 1; i < 1000; i++) {
        for (int j = i + 1; j < 1000; j++) {
            int k = 1000 - i - j;
            
            if (isPyTriplet(i, j, k)) {
                a = i;
                b = j;
                c = k;
            }
        }
    }

    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
    std::cout << "product abc = " << a * b * c << std::endl; 

    return 0;
}