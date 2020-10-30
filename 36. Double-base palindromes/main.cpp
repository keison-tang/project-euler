/*
Problem 36: Double-base palindromes

The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <iostream>
#include <string>
#include <bitset>

/*
    Returns true if a string is palindromic
    @param str String to check for palindromic property
    @return true if the string is a palindrome, else false
*/
bool IsPalindrome(std::string str) {
    int stringLength = str.length();

    // traverse from left to halfway
    for (int i = 0; i < stringLength / 2; i++) {
        // 'mirrored' index from right to halfway
        int j = stringLength - 1 - i;
        
        if (str[i] != str[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    int sum = 0;

    for (int i = 1; i < 1000000; i++) {
        
        std::bitset<20> bin (i);    //max 20 bits to store 1 mil

        std::string str = bin.to_string<char, std::string::traits_type, std::string::allocator_type>();

        str = str.substr(str.find('1'));    //trim leading 0s
        
        if ( IsPalindrome(str) && IsPalindrome(std::to_string(i)) ) {
            sum += i;
        }
    }  

    std::cout << sum << std::endl;

    return 0;
}