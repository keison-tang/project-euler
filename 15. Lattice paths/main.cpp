/*
Problem 15: Lattice paths

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

boost::multiprecision::uint1024_t Factorial(int n) {
    boost::multiprecision::uint1024_t factorial = 1;
    
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    return factorial;
}

int main() {
    const int GRID_SIZE = 20;
    boost::multiprecision::uint1024_t ways = 0;

    ways = Factorial(GRID_SIZE + GRID_SIZE) / (Factorial(GRID_SIZE) * Factorial(GRID_SIZE));

    std::cout << ways << std::endl;

    return 0;
}