/*
Problem 50: Consecutive prime sum

The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include <iostream>
#include <vector>

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

    std::vector<int> primes;
    std::vector<int>::iterator it, windowIndex;
    int i = 1, exceed = 0, windowSize = 0, maxWindowSize = 0, sum = 0, maxCnt = 0, maxPrime = 0;
    bool cont = true;

    //make list of all primes < (1,000,000 / 21) and next 25 primes after that
    while (exceed < 25) {
        if (IsPrime(i)) {
            primes.push_back(i);

            if (i > 1000000/21) exceed++;
        }

        i++;
    }

    //max window size = x, when sum of first x primes exceed 1000000
    it = primes.begin();
    while (sum < 1000000) {
        sum += *it;
        it++;
        maxWindowSize++;
    }

    //start from 21 - derived from description
    for (windowSize = 21; windowSize <= maxWindowSize; windowSize++) {
        //slide window across prime list
        for (it = primes.begin(); it != primes.end() - windowSize; it++) {
            sum = 0;

            for (windowIndex = it; windowIndex != it + windowSize; windowIndex++) {
                sum += *windowIndex;
            }

            if (sum > 1000000) break;   //if window sum exceeds 1 mil, skip to next window size

            if (IsPrime(sum)) { //check if sum is prime
                if (windowSize > maxCnt) { //maxCnt records the most consecutive prime count
                    maxCnt = windowSize;
                    maxPrime = sum;
                }
            }
        }
    }

    std::cout << maxPrime << std::endl;

    return 0;
}