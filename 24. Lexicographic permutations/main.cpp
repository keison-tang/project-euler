/*
Problem 24: Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

FYI: There are 10P10 = 10! permutations = 3628800
*/

#include <iostream>
#include <algorithm>

int main() {
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    std::sort(std::begin(digits), std::end(digits));

    int permCnt = 1; //the first permutation is the above

    while (std::next_permutation(std::begin(digits), std::end(digits))) {
        permCnt++;

        if (permCnt == 1000000) {
            std::cout << digits << std::endl;
            break;
        }
    }

    return 0;
}