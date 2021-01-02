/*
Problem 73: Counting fractions in a range

Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?
*/

#include <iostream>
#include <set>

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
    int larger, smaller, division, remainder = 1;

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
        division = larger / smaller;
        remainder = larger % smaller;

        larger = smaller;
        smaller = remainder;
    }

    return larger;
}

/*
Simplifies a fraction by dividing numerator and denominator by their gcd
*/
fraction SimplifyFraction(fraction f) {
    fraction simple;
    
    int gcd = GCD(f.n, f.d);
    
    simple.n = f.n / gcd;
    simple.d = f.d / gcd;

    return simple;
} 

int main() {

    fraction f;
    std::set<fraction> fractions; //unique and ordered set

    for (int d = 1; d <= 12000; d++) {
        for (int n = 1; n <= (d/2 + 1); n++) { //check numerators up to 1/2
            if ((((double)n / (double)d) < (1.0 / 2.0)) 
            && (((double)n / (double)d) > (1.0 / 3.0))) { //only add to set if <1/2 and >1/3
                f.n = n;
                f.d = d;

                f = SimplifyFraction(f);

                fractions.insert(f);
            }      
        }
    }

    std::cout << fractions.size() << std::endl;

    return 0;
}