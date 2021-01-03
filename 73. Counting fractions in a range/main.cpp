/*
Problem 73: Counting fractions in a range

Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?
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

    fraction f;
    int cnt = 0;

    double lb, ub, dec;
    lb = 1.0 / 3.0;
    ub = 1.0 / 2.0;

    for (int d = 1; d <= 12000; d++) {
        for (int n = (d/3 -1); n <= (d/2 + 1); n++) { //check numerators between 1/3 to 1/2

            dec = (double)n / (double)d;

            if ((dec > lb) && (dec < ub)) { //if <1/2 and >1/3
                f.n = n;
                f.d = d;

                //if fraction can be reduced then its already been counted before
                if (IsIrreducableFraction(f)) {
                    cnt++;
                }
            }      
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}