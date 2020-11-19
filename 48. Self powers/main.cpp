/*
Problem 48: Self powers

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <iostream>

/*
Truncates an input number to the 10 lowest place value digits
*/
unsigned long long TruncTenDigits(unsigned long long num) {
    return (num % 10000000000);
}

int main() {
    unsigned long long sum = 0;

    for (int i = 1; i <= 1000; i++) {
        unsigned long long tmp = i;

        for (int j = 1; j < i; j++) {   //calculate self power, truncating to 10 digits each time
            tmp *= i;
            tmp = TruncTenDigits(tmp);
        }

        sum += tmp;
        sum = TruncTenDigits(sum);
    }

    std::cout << sum << std::endl;

    return 0;
}