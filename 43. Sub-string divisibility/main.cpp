/*
Problem 43: Sub-string divisibility

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <iostream>
#include <algorithm>
#include <string>

int main() {
    unsigned long long sum = 0;
    
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::sort(std::begin(digits), std::end(digits));

    while (std::next_permutation(std::begin(digits), std::end(digits))) {
        std::string str = digits; //char[] to string, to use substr

        if ( //check sub-str divisibility properties
            (std::stoi(str.substr(1, 3)) % 2 == 0) &&
            (std::stoi(str.substr(2, 3)) % 3 == 0) &&
            (std::stoi(str.substr(3, 3)) % 5 == 0) &&
            (std::stoi(str.substr(4, 3)) % 7 == 0) &&
            (std::stoi(str.substr(5, 3)) % 11 == 0) &&
            (std::stoi(str.substr(6, 3)) % 13 == 0) &&
            (std::stoi(str.substr(7, 3)) % 17 == 0)
        ) {
            sum += std::stoll(str);

            //std::cout << std::stoll(str) << std::endl;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}