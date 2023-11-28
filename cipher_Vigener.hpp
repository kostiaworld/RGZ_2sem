//
//  cipher_Vigener.hpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#ifndef cipher_Vigener_hpp
#define cipher_Vigener_hpp

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

string getkey_Vigener();

void generate_alfavit(map<char, int> &alfavit);

string generateKey(string Original_text, string key);

string encrypted_text_func(vector<int>&original_text_vector, vector<int>&key_vector, vector<int>&encrypted_text_vector, string Original_text, string key, map<char, int> &alfavit);

string decrypted_text_func(vector<int>&encrypted_text_vector, vector<int>&key_vector, map<char, int> &alfavit, string Original_text, string key);


#endif /* cipher_Vigener_hpp */
