/*
Problem 39: Integer right triangles

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <iostream>

/*
Rules:
a, b, c are integers and > 0
a < b < c
a + b + c = p
a^2 + b^2 = c^2

Rule 2: A right angled triangle can be isosceles but side c won't be integer. Also to prevent duplicate solutions e.g b^2 + a^2 = c^2
*/

int main() {
    int maxP = 0, maxSolutions = 0;

    for (int p = 1; p <= 1000; p++) {
        int solutions = 0;
        
        for (int a = 1; a <= p/2; a++) {    // rule 1
            for (int b = 1; b <= p/2; b++) {    // rule 1
                int c = p - a - b; // rule 3

                // rule 2 and 4
                if ( ((a*a + b*b) == c*c) && (a<b) && (b<c) ) {
                    //std::cout << p << " " << a << " " << b << " " << c << std::endl; 
                    solutions++;
                }
            }
        }

        if (solutions > maxSolutions) {
            maxP = p;
            maxSolutions = solutions;
        }
    }

    std::cout << "p = " << maxP << " has " << maxSolutions << " solutions" << std::endl;

    return 0;
}