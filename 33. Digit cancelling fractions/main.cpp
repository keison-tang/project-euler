/*
Problem 33: Digit cancelling fractions

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <iostream>
#include <algorithm>
#include <string>

/*
Compares a fraction before and after 'simplification' by cancelling a common digit
@param numerator Numerator of fraction
@param denominator Denominator of fraction
@return True if value of fraction is the same after digit cancellation, else false
*/
bool DigitCancelFraction(int numerator, int denominator) {
    if (numerator >= denominator) return false;  //fraction less than 1
    if ((numerator < 10) || (numerator > 99)) return false; //2 digit numerator
    if ((denominator < 10) || (denominator > 99)) return false; //2 digit denominator
    if ((numerator % 10 == 0) || (denominator % 10 == 0)) return false; //no trivial example

    float orig = (float)numerator / denominator;
    float canc = 0;

    std::string numStr, denStr;

    numStr = std::to_string(numerator);
    denStr = std::to_string(denominator);

    std::sort(numStr.begin(), numStr.end());
    std::sort(denStr.begin(), denStr.end());

    if (numStr == denStr) return false; //only one digit is common across both nums

    //cancel the common digit and compare
    if (numStr[0] == denStr[0]) {
        canc = (float)(numStr[1] - '0') / (denStr[1] - '0'); //char - '0' converts to int
        return (orig == canc);
    } else if (numStr[0] == denStr[1]) {
        canc = (float)(numStr[1] - '0') / (denStr[0] - '0');
    } else if (numStr[1] == denStr[0]) {
        canc = (float)(numStr[0] - '0') / (denStr[1] - '0');
        return (orig == canc);
    } else if (numStr[1] == denStr[1]) {
        canc = (float)(numStr[0] - '0') / (denStr[0] - '0');
    } else {
        return false;
    }

    return (orig == canc);
}

int main() {
    int numerProd = 1, denomProd = 1;

    for (int denom = 11; denom < 100; denom++) {
        for (int numer = 10; numer < denom; numer++) {
            if (DigitCancelFraction(numer, denom)) {
                numerProd *= numer;
                denomProd *= denom;
                
                //std::cout << numer << " / " << denom << std::endl;
            }
        }
    }

    std::cout << (float)numerProd / denomProd << std::endl;

    return 0;
}