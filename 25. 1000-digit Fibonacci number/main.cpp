/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_int.hpp> //for arbitrary precision integer
#include <boost/lexical_cast.hpp>

int main() {
    boost::multiprecision::cpp_int prevprev = 1;    //Fn-2
    boost::multiprecision::cpp_int prev = 1;    //Fn-1

    int digitLen = 1;
    int n = 3;

    while (digitLen < 1000) {
        boost::multiprecision::cpp_int term = prev + prevprev;

        digitLen = boost::lexical_cast<std::string>(term).length();

        //std::cout << n << " " << digitLen << " " << term << std::endl;
        std::cout << n << " " << digitLen << std::endl;

        n++;
        prevprev = prev;
        prev = term;
    }

    

    return 0;
}