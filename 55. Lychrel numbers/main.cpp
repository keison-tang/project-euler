/*
Problem 55: Lychrel numbers

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

/*
    Returns true if an input string is palindromic
*/
bool IsPalindrome(std::string str) {
    int j = str.length() - 1;

    for (int i = 0; i <= str.length() / 2; i++) {
        if (str[i] != str[j-i]) {
            return false;
        }
    }

    return true;
}

/*
    Reverses a string
*/
std::string Reverse(std::string str) {
    int j;
    char tmp;

    while (str.back() == '0') {
        str.pop_back();
    }

    j = str.length() - 1;

    for (int i = 0; i < str.length() / 2; i++) {
        tmp = str[i];

        str[i] = str[j-i];
        str[j-i] = tmp;
    }

    return str;
}

/*
    Returns true if the input number is a Lychrel number: 
    a number that doesn't form a palindrome within 50 iterations of the 196-Algorithm
*/
bool IsLychrel(int num) {
    int iters = 0;
    boost::multiprecision::cpp_int n = num;

    while (iters < 50) {
        n += boost::lexical_cast<boost::multiprecision::cpp_int>(Reverse(boost::lexical_cast<std::string>(n)));

        iters++;

        if (IsPalindrome(boost::lexical_cast<std::string>(n))) return false;
    }

    return true;
}

int main() {
    int cnt = 0;

    for (int i = 1; i < 10000; i++) {
        if (IsLychrel(i)) cnt++;
    }
    
    std::cout << cnt << std::endl;

    return 0;
}