//
//  cipher_Polybius_Square.hpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#ifndef cipher_Polybius_Square_hpp
#define cipher_Polybius_Square_hpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;
string getkey_Polybius_Square();

string DeleteDuplicates(string str);

void square_map(string key, map <char, string> &square);

string encryption(map <char, string> square, string text);

string decryption(map <char, string> square, string text);



#endif /* cipher_Polybius_Square_hpp */
