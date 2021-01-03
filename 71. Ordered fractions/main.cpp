/*
Problem 71: Ordered fractions

Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that 2/5 is the fraction immediately to the left of 3/7.

By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.
*/

#include <iostream>

/*
Struct for a fraction, n numerator, d denominator
Custom comparison function for set compare
*/
struct fraction {
    int n;
    int d;

    bool operator < (const fraction& rhs) const {
        double a,b;

        a = (double)this->n / (double)this->d;
        b = (double)rhs.n / (double)rhs.d ;

        return (a < b);
    }
};

/*
Implements Euclid's Algorithm for finding gcd of two integers
@param a first integer 
@param b second integer
@returns GCD of integers a and b
*/
int GCD(int a, int b) {
    int larger, smaller, remainder = 1;

    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    }

    if (a == b) {
        return a;
    } else if (a > b) {
        larger = a;
        smaller = b;
    } else {
        larger = b;
        smaller = a;
    }
    
    while (remainder != 0) {
        remainder = larger % smaller;
        larger = smaller;
        smaller = remainder;
    }

    return larger;
}

/*
Simplifies a fraction by dividing numerator and denominator by their gcd
*/
void SimplifyFraction(fraction& f) {
    int gcd = GCD(f.n, f.d);
    
    f.n /= gcd;
    f.d /= gcd;
} 

/*
Returns true if the fraction cannot be simplified
*/
bool IsIrreducableFraction(const fraction& f) {
    return GCD(f.n, f.d) == 1;
}

int main() {

    fraction f, left;

    left.n = 1;
    left.d = 4;

    for (int d = 2; d <= 1000000; d++) {
        for (int n = (d/7*3 - 5); n < (d/7*3 + 5); n++) { //check values around 3/7
            if (((double)n / (double)d) < (3.0 / 7.0)) { //only check if < 3/7
                f.n = n;
                f.d = d;

                //if 'f' is larger than 'left' then it's closer to 3/7, update value
                if (IsIrreducableFraction(f) && (left < f)) {
                    left = f;
                }
            } else {
                continue;   //skip iteration if n values form fraction larger than 3/7
            }     
        }
    }

    std::cout << left.n << " / " << left.d << std::endl;

    return 0;
}