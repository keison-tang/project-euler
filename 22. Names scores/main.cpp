/*
Problem 22: Names scores

Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <cstring>

/*
Returns position of letter on alphabet
@param letter Letter to get position of
@return Returns position of letter on alphabet
*/
int AlphabetPosition(char letter) {
    return toupper(letter) - 64;    //capital letters start at 65 on ASCII table
}

/*
Returns the value of a word by summing the alphabetical position of each char
@param word
@returns Sum of each char's alphabetical position
*/
int WordValue(std::string word) {
    int sum = 0;
    
    for (std::string::iterator it = word.begin(); it != word.end(); it++) {
        sum+= AlphabetPosition(*it);
    }
    
    return sum;
}

int main() {
    std::vector<std::string> names;
    char name[50];
    unsigned long long totalValue = 0;

    std::ifstream nameFile;
    nameFile.open("p022_names.txt");
    
    if (nameFile.is_open()) {
        while (nameFile.good()) {
            nameFile.getline(name, 100, ','); // read file until , delimiter

            std::string str = name;
            str.erase(std::remove(str.begin(), str.end(), '"'), str.end()); // remove "
            
            names.push_back(str);   // add to vector
        }

        nameFile.close();
    } else {
        std::cout << "File not found" << std::endl;
    }

    // use std sort to order all names alphabetically
    std::sort(names.begin(), names.end());


    // loop through the vector and calculate position * name value
    int i = 1;

    for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); it++) {
        totalValue += i * WordValue(*it);

        i++;
    }

    std::cout << "Total value: " << totalValue << std::endl;

    return 0;
}