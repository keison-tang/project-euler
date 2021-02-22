/*
Problem 44: Pentagon numbers

Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
*/

#include <iostream>
#include <unordered_set>

int main() {

    int n = 1;
    int Pj, Pk, Pn, D;
    std::unordered_set<int> numbers;
    std::unordered_set<int>::iterator it, find;
    bool cont = true;

    while (cont) {
        Pn = n * (3*n - 1) / 2; //say Pn is the "sum"
        
        //try each pent number in the vector
        for (it = numbers.begin(); it != numbers.end(); it++) {
            Pj = *it;
            Pk = Pn - Pj; //Pk = 'sum' - Pj

            find = numbers.find(Pk); //find Pk in pentagonal list

            if (find != numbers.end()) {    //Pk is pentagonal
                D = Pk - Pj;
                if (D < 0) {D*-1;}

                find = numbers.find(D); //find D in pentagonal list

                if (find != numbers.end()) {    //D is pentagonal, done
                    std::cout << D << std::endl;
                    cont = false;
                    break;
                }
            }
        }

        numbers.insert(Pn);
        n++;
    }

    return 0;
}