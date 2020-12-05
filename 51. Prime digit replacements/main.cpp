/*
Problem 51: Prime digit replacements

By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

/*
    Returns true if the number is a prime number
*/
bool IsPrime(int number) {
    if (number <= 3) {
        return (number > 1);   // 2 and 3 is prime
    } else if (((number % 2) == 0) || ((number % 3) == 0)) {
        return false;   // divisible by 2 or 3 not primes
    }

    int i = 5;

    while ((i * i) <= number) {
        if (((number % i) == 0) || ((number % (i + 2)) == 0)) {
            return false;
        }
        i += 6;
    }

    return true;
}


int main() {
    int i = 1, cnt = 0;
    std::unordered_set<char> digits;

    while (cnt != 8) {
        i += 2;

        if (IsPrime(i)) {
            std::string str = std::to_string(i);

            //unique chars in string
            for (char const &c: str) {
                digits.insert(c);
            }

            //replace with 0-9 for each unique char
            for (const char& elem: digits) {
                cnt = 0;
                
                for (int j = 48; j <= 57; j++) { //ascii decimal 0-9
                    std::string tmp = str;
                    std::replace(tmp.begin(), tmp.end(), elem, (char)j);
                    int num = std::stoi(tmp);

                    if (IsPrime(num) && (num >= i)) {
                        //check the generated num is not less than original e.g 13, 03 doesn't count, 13 counts 
                        cnt++;
                    }
                }
            }
        }

        digits.clear();

    }

    std::cout << i << std::endl; 

    return 0;
}