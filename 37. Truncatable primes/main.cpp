/*
Problem 37: Truncatable primes

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <iostream>
#include <string>

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

std::string PopLeft(std::string str) {
    std::string tmp = str;
    tmp.erase(tmp.begin());
    return tmp;
}

std::string PopRight(std::string str) {
    std::string tmp = str;
    tmp.pop_back();
    return tmp;
}

int main() {
    int primes = 0, sum = 0, i = 11; //start at 11 as 2,3,5,7 not considered truncatable primes

    while (primes != 11) {  //there are 11 truncatable primes
        if (IsPrime(i)) {
            int ltr = i, rtl = i;

            while (ltr > 9) {   //keep truncating until single digit
                ltr = stoi(PopLeft(std::to_string(ltr)));
                rtl = stoi(PopRight(std::to_string(rtl)));

                if (IsPrime(ltr) && IsPrime(rtl)) {
                    if (ltr < 10) { //if single digit = prime then orig num = truncatable prime
                        primes++;
                        sum += i;
                    }
                } else {
                    break;
                }
            }
        }

        i += 2;
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}