/*
Problem 16: Power digit sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

FYI: cba implementing long addition again so used boost lib
*/

#include <iostream>
#include <string>
#include <cmath>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

int main() {
    boost::multiprecision::uint1024_t result = 0;
    std::string str;
    unsigned int sum = 0;

    result = (boost::multiprecision::uint1024_t)pow(2, 1000);
    str = boost::lexical_cast<std::string>(result);

    //std::cout << result << std::endl;

    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        sum += *it - '0';   //char to int
    }
    
    std::cout << sum << std::endl;
}