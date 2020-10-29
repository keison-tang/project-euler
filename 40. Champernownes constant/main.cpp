/*
Problem 40: Champernowne's constant 

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <string>

#define TARGET 1000000

/*
Finds nth digit of a sequence of numbers in string format
@param str Sequence of numbers as string
@param n nth digit to get
@return Digit n in integer form
*/
unsigned int NthDigit(std::string str, int n) {
    return str.at(n-1) - '0';
}

int main() {
    std::string champConstant;
    unsigned int i = 1;

    while (champConstant.size() < TARGET) {
        champConstant += std::to_string(i);

        i++;
    }

    unsigned int product = 
    NthDigit(champConstant, 1) * 
    NthDigit(champConstant, 10) * 
    NthDigit(champConstant, 100) * 
    NthDigit(champConstant, 1000) * 
    NthDigit(champConstant, 10000) * 
    NthDigit(champConstant, 100000) * 
    NthDigit(champConstant, 1000000);

    std::cout << product << std::endl;

    return 0;
}