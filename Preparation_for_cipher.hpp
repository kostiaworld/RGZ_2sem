//
//  Preparation_for_cipher.hpp
//  Final_project_cipher
//
//  Created by Константин on 09.10.2023.
//

#ifndef Preparation_for_cipher_hpp
#define Preparation_for_cipher_hpp

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

#include "cipher_Hill.hpp"
#include "cipher_Polybius_Square.hpp"
#include "cipher_Vigener.hpp"
#include "Read_write_control.hpp"

#define M 3
#define N 3


using namespace std;

void Preparation_for_cipher_hill_encryption(string);
void Preparation_for_cipher_hill_desencryption(string);

void Preparation_for_cipher_vigener_encryption(string);
void Preparation_for_cipher_vigener_desencryption(string);

void Preparation_for_cipher_polybius_square_encryption(string);
void Preparation_for_cipher_polybius_square_desencryption(string);


#endif /* Preparation_for_cipher_hpp */
