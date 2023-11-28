//
//  Read_write_control.cpp
//  Final_project_cipher
//
//  Created by Константин on 10.10.2023.
//

#include "Read_write_control.hpp"


void File_write(string Cipher_Text, string file_name){
    ofstream Myfile(file_name);
    Myfile << Cipher_Text;
    Myfile.close();
}

string File_read(string file_name){
    ifstream Myfile(file_name);
    Myfile.is_open();
    stringstream Text_File;
    Text_File << Myfile.rdbuf();
    
    return Text_File.str();
}
