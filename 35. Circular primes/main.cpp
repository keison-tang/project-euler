/*
Problem 35: Circular primes
 
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

#include <iostream>
#include <string>

/*
Rotates the chars of an input string to the right by 1 char
@param str String to rotate
@return Rotated string
*/
std::string RotateRight(std::string str) {
    if (stoi(str) < 10) {
        return str;
    }

    std::string tmp = str;

    tmp.insert(tmp.begin(), tmp.back());    //insert back char at front
    tmp.pop_back(); //pop back char

    return tmp;
}

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
    int count = 0;

    for (int i = 1; i < 1000000; i++) {
        if (IsPrime(i)) {   //already tested original number
            std::string str = std::to_string(i);

            for (int j = 1; j <= str.length(); j++) {   //test each rotation for prime
                str = RotateRight(str);

                if (IsPrime(std::stoi(str))) {
                    if (j == str.length()) {    //all rotations are primes
                        count++;
                    }
                } else {
                    break;  //a rotation is not prime, try next number
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}