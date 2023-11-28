//
//  cipher_Hill.hpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#ifndef cipher_Hill_hpp
#define cipher_Hill_hpp

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

#include "fool_test.hpp"

using namespace std;

//string getkey_Hill();
//template <size_t r, size_t c>
int assign_Hill(int (&key_matr)[3][3]);
int assign_Hill_generete(int (&key_matr)[3][3]);

void generete_alfavit_Hill(map<char, int> (&alfavit));

//template <size_t r, size_t c>
string encryption_Hill(map<char, int> alfavit, int (&key_matr)[3][3] ,vector<int> &sum, string text, int &Namber);

int modInverse_Hill(int, int);

//template <size_t r, size_t c>
void invertMatrix_Hill(int (&key_matr)[3][3]);

//template <size_t r, size_t c>
string desencryption_Hill(map<char, int> alfavit,int (&key_matr)[3][3] ,vector<int> &sum, int &Namber  );


#endif /* cipher_Hill_hpp */
