/*
Problem 45: Triangular, pentagonal, and hexagonal

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
Pentagonal	 	Pn=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.

FYI: watch your data types
*/

#include <iostream>
#include <cmath>

unsigned int NthTriNum(unsigned int n) {
    return n * (n + 1) / 2;
}

unsigned int NthPenNum(unsigned int n) {
    return n * (3*n - 1) / 2;
}

unsigned int NthHexNum(unsigned int n) {
    return n * (2*n - 1);
}

int main() {

    unsigned int Tn = 1, Pn = 1, Hn = 1, tIndex = 1, pIndex = 1, hIndex = 1, cnt = 0;

    while (cnt < 3) {
        while (Tn < Pn) {   //Catch up to Pn
            tIndex++;
            Tn = NthTriNum(tIndex);
        }

        while (Pn < Hn) {   //Catch up to Hn
            pIndex++;
            Pn = NthPenNum(pIndex);
        }

        while (Hn < Pn) {   //Catch up to Pn
            hIndex++;
            Hn = NthHexNum(hIndex);
        }
        
        if ((Tn == Pn) && (Pn == Hn)) {
            cnt++;

            std::cout << Tn << " : " << tIndex << " " << pIndex << " " << hIndex << std::endl;

            //increment hex sequence to get the process going again
            hIndex++;   
            Hn = NthHexNum(hIndex);
        }
    }
       



    return 0;
}