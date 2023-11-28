//
//  main.cpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#include <iostream>

#include "Menu_system_code.hpp"
#include "System_security_check.hpp"
 
using namespace std;

int main(){
    
    string file_name;

    SecurityCheck();

    file_name = Menu();

}
