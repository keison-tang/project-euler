/*
Problem 42: Coded triangle numbers

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <cmath>

/*
Finds position of input letter in alphabet from 1-26 (A-Z)
@param letter to check position of
@returns Position of letter in alphabet
*/
int AlphabetPos(char letter) {
    char letter1 = toupper(letter);
    return letter1 - 64;
}

/*
Finds the value of a word by summing the alphabetical position of each character
@param word Input word
@returns Value of word
*/
int WordValue(std::string word) {
    int value = 0;

    for (const char& let : word) {
        value += AlphabetPos(let);
    }

    return value;
}

/*
Determines if a number is a triangle number. We have a quadratic from the given sequence formula: n^2 + n - 2tn
@param tn number to check
@return true if input number is triangle number, else false
*/
bool IsTriangleNum(unsigned int tn) {
    int a = 1;
    int b = 1;
    int c = -2 * tn;

    float n1, n2;

    n1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
    n2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);

    //n must be greater than 0 and a whole number
    if ((n1 > 0) || (n2 > 0)) {
        if ((fmod(n1, 1) == 0) || (fmod(n2, 1) == 0)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

int main() {
    int count = 0;
    std::string word;

    std::ifstream ifs ("p042_words.txt", std::ifstream::in);

    while (ifs.good()) {
        std::getline(ifs, word, ',');
        word.erase(remove(word.begin(), word.end(), '"'), word.end());

        if (IsTriangleNum(WordValue(word))) {
            count++;
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}