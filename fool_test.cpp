//
//  fool_test.cpp
//  Final_project_cipher
//
//  Created by Константин on 18.10.2023.
//

#include "fool_test.hpp"

int fool_text(int same_namber){
    bool Exodus;
    string Intermediate_element;
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            
            if ( Intermediate_element == "" and Intermediate_element == " ") {
                throw 505;
            };
            Exodus = true;
        }
        catch (int myNum){
            
            cout << "Ошибка ввода...  {№" << myNum << "}\n";
        }
    } while (Exodus == false);
    return same_namber;
}
