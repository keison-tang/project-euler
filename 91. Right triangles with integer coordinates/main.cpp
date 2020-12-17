/*
Problem 91: Right triangles with integer coordinates

The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.

There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; that is,
0 ≤ x1, y1, x2, y2 ≤ 2.

Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

/*
Returns true if the three points form a right triangle
@param x1 x-coord of point 1
@param y1 y-coord of point 1
@param x2 x-coord of point 2
@param y2 y-coord of point 2
@param x3 x-coord of point 3
@param y3 y-coord of point 3
@returns true if three input points form right triangle, else false
*/
bool IsRightTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    std::array<int, 3> abc;

    abc[0] = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    abc[1] = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    abc[2] = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);

    std::sort(abc.begin() ,abc.end());

    return ((abc[0] + abc[1]) == abc[2]);
}

int main() {
    const int SIZE = 50;

    //create a vector of coordinates going from left to right, bottom to top, excl (0,0)
    struct coord
    {
        int x;
        int y;
    };

    std::vector<coord> coords;
    
    for (int y = 0; y <= SIZE; y++) {
        for (int x = 0; x <= SIZE; x++) {
            coord pt;
            
            if (x == 0 && y == 0) {
                continue;   //skip (0,0)
            } else {
                pt.x = x;
                pt.y = y;
            }

            coords.push_back(pt);
        }
    }
    
    /*
    brute force all combinations, no repeats
    Point 1: is given: 0,0
    Point 2: fixed: from start to 2nd to last point
    Point 3: move: from 1 point ahead of fixed to end
    */
    std::vector<coord>::iterator fixed, move;
    int cnt = 0;

    for (fixed = coords.begin(); fixed < coords.end() - 1; fixed++) {
        for (move = fixed + 1; move != coords.end(); move++) {
            if (IsRightTriangle(0,0,fixed->x,fixed->y,move->x,move->y)){
                cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}