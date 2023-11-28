//
//  Menu_system_code.hpp
//  Final_project_cipher
//
//  Created by Константин on 09.10.2023.
//

#ifndef Menu_system_code_hpp
#define Menu_system_code_hpp

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


#include "Preparation_for_cipher.hpp"
#include "Read_write_control.hpp"


using namespace std;


string Menu();

void question_about_method_encryption(string file_name);

void question_about_method_desencryption(string file_name);



#endif /* Menu_system_code_hpp */
