//
//  System_security_check.cpp
//  Final_project_cipher
//
//  Created by Константин on 10.10.2023.
//

#include "System_security_check.hpp"


bool SecurityCheck(){
    
    string password = "";

    bool Exodus = false;
    
    do{
        try{
            cout << "Необходимо ввети пароль для входа: ";
            getline(cin, password);
            if (password != PASSWORD) {
                throw runtime_error("Неверный пароль! Пожалуйста попробуйте еще раз.\n");
            }
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);

    system("clear");
    cout << "Проверка личности завершена" << endl;
    return true;
}
