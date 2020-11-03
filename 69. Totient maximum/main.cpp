/*
Problem 69: Totient maximum

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

n	Relatively Prime	φ(n)	n/φ(n)
2	1	                1	    2
3	1,2	                2	    1.5
4	1,3	                2       2
5	1,2,3,4	            4	    1.25
6	1,5	                2	    3
7	1,2,3,4,5,6	        6	    1.1666...
8	1,3,5,7	            4	    2
9	1,2,4,5,7,8	        6	    1.5
10	1,3,7,9	            4	    2.5

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

FYI: a number is relatively prime to another number if their greatest common divisor is 1.
https://en.wikipedia.org/wiki/Euler%27s_totient_function

v1: 3 min 20 sec runtime
*/

#include <iostream>
#include <map>

#include <cmath>

/*
    Returns true if the number is a prime number
*/
bool IsPrime(int number) {
    if (number <= 3) {
        return (number > 1);   // 2 and 3 is prime
    } else if (((number % 2) == 0) || ((number % 3) == 0)) {
        return false;   // divisible by 2 or 3 not primeFactors
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
Euler's Totient function (phi function). Implements Euler's product formula
@param n Number to check
@return Number of numbers less than n which are relatively prime to n
*/
int TotientFunction(int n) {
    //prime factorisation - division method
    std::map<int, int> primeFactors;    //key: prime factor, value: exponent

    int tmp = n;

    while (tmp != 1) {
        int i = 2;
        int primeDivisor;

        while (1) { // find smallest prime factor
            if (((tmp % i) == 0) && (IsPrime(i))) {
                primeDivisor = i;
                break;
            }

            i++;
        }

        std::map<int, int>::iterator it = primeFactors.find(primeDivisor);

        if (it != primeFactors.end()) {   // found, iterate exponent
            it -> second += 1;
        } else {    // not found, create pair
            primeFactors.insert(std::pair<int, int>(primeDivisor, 1));
        }

        tmp /= primeDivisor;
    }

    // phi(n) = multiply together each (exponent + 1)
    int product = 1;

    for (const auto& pair : primeFactors) { //ref to avoid copying
        product *=  pow(pair.first, pair.second - 1) * (pair.first - 1);
    }

    return product;
}

int main() {
    int maxN = 0;
    double max = 0.0;    //max n/phi(n)

    for (int n = 2; n <= 1000000; n++) {
        //std::cout << n << " : " << ((double)n / TotientFunction(n)) << std::endl;
        
        if (((double)n / TotientFunction(n)) > max) {
            maxN = n;
            max = (double)n / TotientFunction(n);
        }
    }

    std::cout << maxN << " : " << max << std::endl;

    return 0;
}