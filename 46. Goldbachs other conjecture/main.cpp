/*
Problem 46: Goldbach's other conjecture

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

#include <iostream>
#include <cmath>

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
    int oddComp = 9;

    while(1) {
        bool found = false;

        //check each odd composite
        if (!IsPrime(oddComp)) { //composites, so not primes
            
            //test the conjecture: oddComp == prime + 2 x base^2 
            //find a prime and test
            for (int prime = 1; prime < oddComp; prime += 2) { 
                if (IsPrime(prime)) { 
                    float base = sqrt((oddComp - prime) / 2);

                    //if base is an integer then the conjecture is true
                    if (fmod(base, 1.0) == 0) {
                        found = true;
                        break; //move onto next odd composite
                    }
                }
            }

            //been through all primes, oddComp != prime + 2 x base^2
            if (!found) {
                std::cout << oddComp << std::endl;
                break;
            }
        }

        oddComp += 2; //increment by 2 as odd numbers only
    }

    return 0;
}