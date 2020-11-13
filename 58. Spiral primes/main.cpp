/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
*/

#include <iostream>

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
    //all initialised to 1 (except primeCnt bc 1 isn't prime) because the inner most layer is just 1
    int layerStart = 1, sideLen = 1, diagCnt = 1, primeCnt = 0, tr = 1, tl = 1, bl = 1, br = 1;
    float ratio = 1.0;

    while (ratio > 0.1) {
        layerStart = br + 1;    // starting number layer = prev layer's bottom right corner + 1
        sideLen += 2;
        diagCnt += 4;

        // calculate four corners (diagonals)
        tr = layerStart + sideLen - 2;
        tl = tr + sideLen - 1;
        bl = tl + sideLen - 1;
        br = bl + sideLen - 1;

        if (IsPrime(tr)) primeCnt++;
        if (IsPrime(tl)) primeCnt++;
        if (IsPrime(bl)) primeCnt++;
        if (IsPrime(br)) primeCnt++;

        ratio = (float)primeCnt / diagCnt;

        //std::cout << sideLen << " " << layerStart << " " << tr << " " << tl << " " << bl << " " << br << " " << ratio << std::endl;
    }

    std::cout << sideLen << std::endl;

    return 0;
}