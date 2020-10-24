/*
Problem 17: Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

const std::map<int, std::string> kStringLookupTable = {
    {1,"one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"},
    {100, "hundred"},
    {1000, "thousand"},
    };


/*
Returns a number written out in words
@param n A number between 1-999
@returns A string representing a number in word form
*/
std::string threeDigits2Words(int n) {
    std::string words = "";
    
    // words for 100's place value
    if (n > 99) {
        int hundredsPlace = n / 100;
        
        words += kStringLookupTable.find(hundredsPlace)->second + " hundred";

        if ((n % 100) != 0) { // 10's or 1's place value non 0
            words += " and ";
        }
    } 
    
    // words for 10's and/or 1's place value
    if ((n % 100) <= 20) { // single word
        words += kStringLookupTable.find(n % 100)->second;
    } else { // 10's and 1's value between 21-99
        int tensPlace = (n % 100) / 10;
        
        words += kStringLookupTable.find(tensPlace * 10)->second;

        if ((n % 10) != 0) { // hyphenated word for 1's value
            int onesPlace = n % 10;

            words += "-" + kStringLookupTable.find(onesPlace)->second;
        }
    }

    return words;
}

int main() {
    int letterCount = 0;

    for (int i = 1; i <= 1000; i++) {
        std::string words = "";
        
        //digits 4-6
        if ((i / 1000) != 0) {
            int thousands = i / 1000;
            words += threeDigits2Words(thousands) + " thousand";

            if ((i % 1000) != 0) {
                words += " ";
            }
        }

        //digits 1-3
        words += threeDigits2Words(i % 1000);

        //std::cout << i << " : " << words << std::endl;

        //strip spaces and hyphens
        words.erase(std::remove(words.begin(), words.end(), ' '), words.end());
        words.erase(std::remove(words.begin(), words.end(), '-'), words.end());

        //std::cout << i << " : " << words << std::endl;

        letterCount += words.length();
    }
    
    std::cout << letterCount << std::endl;

    return 0;
}