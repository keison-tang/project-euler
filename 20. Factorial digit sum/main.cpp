/*
Problem 20: Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

boost::multiprecision::uint1024_t NFactorial(int n) {
    boost::multiprecision::uint1024_t total = n;

    for (int i = n - 1; i > 0; i--) {
        total *= i;
    }

    return total;
}

int main() {
    std::string str;
    unsigned int sum = 0;

    str = boost::lexical_cast<std::string>(NFactorial(100));

    //std::cout << str << std::endl;

    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        sum += *it - '0';   //char to int
    }
    
    std::cout << sum << std::endl;

    return 0;
}