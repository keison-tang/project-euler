/*
Problem 23: Non-abundant sums

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <set>
#include <cmath>

/*
Figures out if a number is an abundant number: where sum of proper divisors exceed the number
@param num Number to check
@returns True if the number is abundant, else false
*/
bool IsAbundantNum(int num) {
    int sum = 1;    //start at 1 to exclude the number itself as it's not proper divisor

    // sum proper divisors
    for (int i = 2; i <= sqrt(num); i++) {  //up to sqrt(num) as divisors come in pairs
        if (num % i == 0 ) {
            if ((num / i) == i) { // divisor is sqrt(num), add divisor once
                sum += i;   
            } else {    // add divisor pair
                sum += i;
                sum += num / i;
            }
        }
    }
    
    return (sum > num);
}

int main() {
    int sum = 0;

    std::set<int>::iterator it;

    std::set<int> abundantNums;  //use set because no duplicates allowed

    // find all abundant nums in range
    for (int i = 1; i <= 28123; i++) {
        sum += i;   // assume all numbers can't be written as sum of 2 abundants - see why later 

        if (IsAbundantNum(i)) {
            abundantNums.insert(i);
        }
    }

    // check if num - abundant = abundant
    for (int i = 1; i <= 28123; i++) {
        for (it = abundantNums.begin(); it != abundantNums.end(); it++) { 
            if (abundantNums.find(i - *it) != abundantNums.end()) {
                sum -= i;   //can be written as sum of 2 abundants, subtract from sum
                break;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}