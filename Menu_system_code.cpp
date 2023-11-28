//
//  Menu_system_code.cpp
//  Final_project_cipher
//
//  Created by Константин on 09.10.2023.
//

#include "Menu_system_code.hpp"


string Menu(){
    string Intermediate_element;
    string file_name;
    string file_text;
    
    bool Exodus = false;
    cout << "Здравствуйте, перед вами которая позволяет выполнять шифровку и дешифровку.\n ------------------------------------------\n Введите <1> если у вас еще нет файла\n Введите <2> если у вас уже есть файла для использования\n";
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            if ( Intermediate_element == "") {
                throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
            };
            if ( Intermediate_element != "2" and Intermediate_element != "1") {
                throw runtime_error("Ошибка ввода (ожидалось 1 или 2) пожалуйста попробуйте еще раз.\n");
            };
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);

    if (Intermediate_element == "1"){
        Exodus = false;
        do{
            Exodus = false;
            cout << "В данное поле необходимо ввести название файла: " << endl;
            getline(cin, file_name);
            try{
                if ( file_name == "") {
                    throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
                };
                Exodus = true;
            }
            catch (const exception& error)
            {
                system("clear");
                cerr << error.what();
            }
        } while (Exodus == false);
        file_name = file_name + ".txt";
        ofstream MyFile(file_name);
        cout << "Введите текст который хотите использовать: " << endl;
        getline(cin, file_text);
        MyFile << file_text;
        MyFile.close();
    }
    
    else {
        cout << "Открываемый вами файл должен находится в папке с мамой программой" << endl;
        Exodus = false;
        do{
            cout << "Укажите название файла: " << endl;
            getline(cin, file_name);
            try{
                if ( file_name == "") {
                    throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
                };
                Exodus = true;
            }
            catch (const exception& error)
            {
                system("clear");
                cerr << error.what();
            }
        } while (Exodus == false);

        file_name = file_name + ".txt";
        file_text = File_read(file_name);

    }
    
    
    cout << "Если у вас есть желание посмотреть содержимое файла то нажмите <1>, если же нет то <2>";
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            if ( Intermediate_element == "") {
                throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
            };
            if ( Intermediate_element != "2" and Intermediate_element != "1") {
                throw runtime_error("Ошибка ввода (ожидалось 1 или 2) пожалуйста попробуйте еще раз.\n");
            };
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);
    string line = "";
    
    
    
    
    if (Intermediate_element == "1"){
        file_text = File_read(file_name);
        cout << file_text;
    }
    
    
    
    
    cout << "\nЧто вы хотите сделать с текстом?\nВведите <1> - выполнить шифрование текста\nВведите <2> - выполнить дешифровку текста";
    cout << "\n";
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            if ( Intermediate_element == "") {
                throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
            };
            if ( Intermediate_element != "2" and Intermediate_element != "1") {
                throw runtime_error("Ошибка ввода (ожидалось 1 или 2) пожалуйста попробуйте еще раз.\n");
            };
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);
    if (Intermediate_element == "1"){
        
        question_about_method_encryption(file_name);
        

    }
    
    else {
        
        question_about_method_desencryption(file_name);
        
        
    }
    return file_name;
}




void question_about_method_encryption(string file_name){
    string Intermediate_element = "";
    bool Exodus = false;
    cout << "Теперь вам необходимо выбрать способ шифрования вашего текста \nВведите <1> - Hill\nВведите <2> - Vigener\nВведите <3> - Polybius_Square";
    cout << "\n";
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            if ( Intermediate_element == "") {
                throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
            };
            if ( Intermediate_element != "2" and Intermediate_element != "1" and Intermediate_element != "3") {
                throw runtime_error("Ошибка ввода (ожидалось 1 или 2 или 3) пожалуйста попробуйте еще раз.\n");
            };
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);
    
    int t = stoi(Intermediate_element);
    switch(t){
        case 1:
            Preparation_for_cipher_hill_encryption(file_name);
            break;
            
        case 2:
            Preparation_for_cipher_vigener_encryption(file_name);
            break;
            
        case 3:
            Preparation_for_cipher_polybius_square_encryption(file_name);
            break;
            
            
    }

}


void question_about_method_desencryption(string file_name){
    string Intermediate_element = "";
    bool Exodus = false;
    cout << "Теперь вам необходимо выбрать способ дешифрования вашего текста \nВведите <1> - Hill\nВведите <2> - Vigener\nВведите <3> - Polybius_Square";
    cout << "\n";
    do{
        Exodus = false;
        getline(cin, Intermediate_element);
        try{
            if ( Intermediate_element == "") {
                throw runtime_error("Вы ничего не ввели в строку ввода пожалуйста попробуйте еще раз.\n");
            };
            if ( Intermediate_element != "2" and Intermediate_element != "1" and Intermediate_element != "3") {
                throw runtime_error("Ошибка ввода (ожидалось 1 или 2 или 3) пожалуйста попробуйте еще раз.\n");
            };
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
    } while (Exodus == false);
    
    int t = stoi(Intermediate_element);
    switch(t){
        case 1:
            Preparation_for_cipher_hill_desencryption(file_name);
            break;
            
        case 2:
            Preparation_for_cipher_vigener_desencryption(file_name);
            break;
            
        case 3:
            Preparation_for_cipher_polybius_square_desencryption(file_name);
            break;
            
            
    }
    
}
