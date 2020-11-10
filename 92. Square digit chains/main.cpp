/*
Problem 92: Square digit chains

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
*/

#include <iostream>
#include <string>


/*
Sums the square of each digit in a specified number
@param num Input number
@return Sum of each individual digit squared
*/
int SquareOfDigits(int num) {
    int sum = 0;
    std::string str = std::to_string(num);

    for (const char& digit : str) {        
        sum += (digit - '0') * (digit - '0'); // convert char digit back to int before multiplying
    }

    return sum;
}


int main() {
    int count = 0;

    for (int i = 1; i < 10000000; i++) {
        int term = i;   //starting term

        if (term == 89) {//if original term is 89, while loop doesn't execute
            count++;
        }

        while ((term != 1) && (term != 89)) {
            term = SquareOfDigits(term); //next term
            
            if (term == 89) {
                count++;
            }
        }
        
    }

    std::cout << count << std::endl;

    return 0;
}