/*
Problem 47: Distinct primes factors

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
*/

#include <iostream>
#include <map>

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

/*
Returns number of distinct prime factors of an input number
@param num Input number
@returns Number of distinct prime factors
*/
int DistinctPrimeFactors(int num) {
    std::map<int, int> factors; //key = prime factor, value = exponent

    int tmp = num;

    //prime factorisation
    while (tmp != 1) {
        int prime = 2;
        
        while (1) { //find smallest prime divisor
            if ((IsPrime(prime) && (tmp % prime == 0))) {
                break;
            } else {
                prime++;
            }
        }

        std::map<int, int>::iterator it = factors.find(prime);

        if (it != factors.end()) {  //factor found in map, increment exponent
            it->second++;
        } else {    //factor not found, create pair
            factors.insert(std::pair<int, int>(prime, 1));
        }

        tmp /= prime;
    }
    
    return factors.size();
}

int main() {
    int a = 1, b = 2, c = 3, d = 4; //distinct prime factors of 4 consecutive ints
    int i = 1; //index

    while (1) {
        if ((a == 4) && (b == 4) && (c == 4) && (d == 4)) {
            break;
        } else {
            a = b; //sliding window
            b = c;
            c = d;
            d = DistinctPrimeFactors(i);

            i++;
        }
    }
    
    //i is 1 ahead of the last of the 4 numbers, so minus 4 to get the first of the 4
    std::cout << i - 4 <<std::endl; 

    return 0;
}