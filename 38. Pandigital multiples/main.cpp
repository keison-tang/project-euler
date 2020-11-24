/*
Problem 38: Pandigital multiples

Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <iostream>
#include <string>
#include <algorithm>

/*
Returns true if the input num is pandigital - contains all digits 1-9 once
*/
bool IsPandigital(int num) {
    std::string str = std::to_string(num);
    std::sort(str.begin(), str.end());

    return (str == "123456789");
}

int main() {
    /*
    As n > 1, we will be concatenating at least 2 numbers together
    Any number > 9999 will give more than 9 digits for n > 1
    */
    int largestNum = 0;

    for (int i = 1; i <= 9999; i++) {
        int num = 0;
        std::string str = "";

        for (int n = 1; n <= 9; n++) { //max n is 9 otherwise will get more than 9 digits
            str += std::to_string(i * n); //concat product to string

            try { //if stoi is out of range then defs not pandigital, skip iteration
                num = stoi(str);
            } catch(const std::exception& e) {
                break;
            }

            if ((n > 1) && IsPandigital(num)) {
                if (num > largestNum) { //update largest pandigital
                    largestNum = num;
                    std::cout << "i: " << i << " n: " << n << " " << largestNum << std::endl;
                }
            }
        }
    }

    return 0;
}