/*
Problem 21: Amicable numbers

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
Returns sum of proper divisors of n (numbers less than n which divide evenly into n)
@param n Number
@return Sum of proper divisors of n
*/
int d(int n) {
    int sum = 0;

    for (int i = 1; i <= n / 2 + 1; i++) {
        if ((n % i) == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    std::vector<int> amicables;

    for (int a = 1; a < 10000; a++) {
        int b = d(a);

        if ( (d(a) == b) && (d(b) == a) && (a != b) ) {
            if ( (a < 10000) && (b < 10000) ) {
                std::vector<int>::iterator ita, itb;
                
                ita = find(amicables.begin(), amicables.end(), a);
                itb = find(amicables.begin(), amicables.end(), b);

                if ( (ita == amicables.end()) && (itb == amicables.end()) ){
                    amicables.push_back(a);
                    amicables.push_back(b);
                }
            }
        }
    }

    int sum = 0;
    for (const auto& a : amicables) {
        sum += a;
    }

    std::cout << sum << std::endl;

    return 0;
}