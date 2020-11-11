/*
Problem 52: Permuted multiples

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

#include <iostream>
#include <string>
#include <algorithm>

/*
Finds out if two input numbers share the same digits
@param a First number
@param b Second number
@returns True if the two numbers share the same digits, else false
*/
bool DigitPermutation(int a, int b) {
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);

    std::sort(strA.begin(), strA.end());
    std::sort(strB.begin(), strB.end());

    if (strA == strB) {
        return true;
    } else {
        return false;
    }
    
    return false;
}

int main() {
    int i = 1;

    while(1) {
        if (DigitPermutation(i, i*2) && 
            DigitPermutation(i*2, i*3) && 
            DigitPermutation(i*3, i*4) &&
            DigitPermutation(i*4, i*5) &&
            DigitPermutation(i*5, i*6)) {
                std::cout << i <<std::endl;
                break;
            }

        i++;
    }
    
    return 0;
}