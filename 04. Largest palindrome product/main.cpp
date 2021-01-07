/*
Problem 4: Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>

/*
    Returns true if a number is a palindromic number
    @param number Number to check for palindromic property
    @return true if the number is a palindrome, else false
*/
bool isPalindrome(int number) {
    std::string numString = std::to_string(number);

    int stringLength = numString.length();

    // traverse from left to halfway
    for (int i = 0; i < stringLength / 2; i++) {
        // 'mirrored' index from right to halfway
        int j = stringLength - 1 - i;
        
        if (numString[i] != numString[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    int largestProduct = 0;
    int multiplicandA = 0;
    int multiplicandB = 0;

    for (int i = 999; i > 0; i--) {
        for (int j = 999; j > 0; j--) {
            int product = i * j;

            if (isPalindrome(product)) {
                if (product > largestProduct) { // if product is larger, then update
                    largestProduct = product;
                    multiplicandA = i;
                    multiplicandB = j;
                }
            }
        }
    }

    std::cout << "Largest palindrome product is: " << largestProduct << std::endl;
    std::cout << "Which is the product of " << multiplicandA << " and " << multiplicandB << std::endl;

    return 0;
}