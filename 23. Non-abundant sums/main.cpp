/*
Problem 23: Non-abundant sums

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <vector>
#include <set>

/*
Figures out if a number is an abundant number: where sum of proper divisors exceed the number
@param num Number to check
@returns True if the number is abundant, else false
*/
bool IsAbundantNum(int num) {
    int sum = 0;

    // sum proper divisors
    for (int i = 1; i < num / 2 + 1; i++) { 
        if (num % i == 0 ) {
            sum += i;
        }
    }
    
    return (sum > num);
}

int main() {
    int sum = 0;

    std::vector<int> abundantNums;
    std::vector<int>::iterator first, second;

    std::set<int> sumCombinations;  //use set because no duplicates allowed

    // find all abundant nums in range
    for (int i = 1; i <= 28123; i++) {
        sum += i;   // assume all numbers can't be written as sum of 2 abundants - see why later 
        
        if (IsAbundantNum(i)) {
            abundantNums.push_back(i);
        }
    }

    // find all combinations of two abundant nums and insert into set
    for (first = abundantNums.begin(); first < abundantNums.end(); first++) {
        for (second = first; second < abundantNums.end(); second++) {
            if ((*first + *second) <= 28123) {
                sumCombinations.insert(*first + *second);
            }
        }
    }

    // subtract each unique combination from the sum
    for (auto comb : sumCombinations) {
        sum -= comb;
    }

    std::cout << sum << std::endl;

    return 0;
}