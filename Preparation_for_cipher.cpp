//
//  Preparation_for_cipher.cpp
//  Final_project_cipher
//
//  Created by Константин on 09.10.2023.
//

#include "Preparation_for_cipher.hpp"


void Preparation_for_cipher_hill_encryption(string file_name){
    
    //string Original_text = "File_read(file_name)";
    
    string Original_text = File_read(file_name);
   // cout << "Изначальный текст: " << Original_text;
    cout << "\n";
    vector<int>sum;
    int Namber = 0;
    int key_matr[3][3];
    
    string encryption_text_Hill = "";
    string desencryption_text_Hill = "";
    map<char, int> alfavit;
    
    cout << "Вы хотите сами задать ключ в виде тройной матрицы или сгенерировать случайно? \n1 - задать вручную \n2 - сгенерировать";
    cout << "\n";
    bool Exodus;
    string Intermediate_element;
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
        assign_Hill(key_matr);
    }
    
    else {
        assign_Hill_generete(key_matr);

    }
    generete_alfavit_Hill(alfavit);

    encryption_text_Hill = encryption_Hill(alfavit, key_matr, sum, Original_text, Namber);
    
    file_name = "encryption_" + file_name;

    File_write(encryption_text_Hill, file_name);
    
}




void Preparation_for_cipher_hill_desencryption(string file_name){
    
    //string Original_text = "File_read(file_name)";
    
    string Original_text = File_read(file_name);
    
    vector<int>sum;
    int Namber = 0;
    int key_matr[3][3];
    cout << "Вам необходимо сейчас задать ключь для декодирования текста \n";
    assign_Hill(key_matr);
    
    string encryption_text_Hill = "";
    string desencryption_text_Hill;
    map<char, int> alfavit;
    
    generete_alfavit_Hill(alfavit);

    //encryption_text_Hill = encryption_Hill(alfavit, key_matr, sum, Original_text, Namber);

    invertMatrix_Hill(key_matr);
    
    for (char const &y: Original_text){
        sum.push_back(alfavit.at(y));
    }
    desencryption_text_Hill = desencryption_Hill(alfavit, key_matr, sum, Namber);
    
    cout << "\n";
    file_name = "desencryption_" + file_name;

    File_write(desencryption_text_Hill, file_name);
    //cout << Original_text1 << "\n";
    
}




void Preparation_for_cipher_vigener_encryption(string file_name){
    
    string key = getkey_Vigener();
    
    vector<int>key_vector;
    vector<int>original_text_vector;
    vector<int>encrypted_text_vector;
    vector<int>decrypted_text_vector;
    
    string Original_text = File_read(file_name);
    
    map<char, int> alfavit;
    generate_alfavit( alfavit );
    key = generateKey(Original_text, key);
    string encrypted_text;
    string decrypted_text;
    
    encrypted_text = encrypted_text_func(original_text_vector, key_vector, encrypted_text_vector, Original_text, key, alfavit);

    cout << "\n";
    //decrypted_text = decrypted_text_func(encrypted_text_vector, key_vector, alfavit, Original_text);
    
    file_name = "encryption_" + file_name;

    File_write(encrypted_text, file_name);
}




void Preparation_for_cipher_vigener_desencryption(string file_name){
    
    string key = getkey_Vigener();
    
    vector<int>key_vector;
    vector<int>original_text_vector;
    vector<int>encrypted_text_vector;
    vector<int>decrypted_text_vector;
    
    string Original_text = File_read(file_name);
    
    map<char, int> alfavit;
    generate_alfavit( alfavit );
    key = generateKey(Original_text, key);
    string encrypted_text;
    string decrypted_text;
    
    //encrypted_text = encrypted_text_func(original_text_vector, key_vector, encrypted_text_vector, Original_text, key, alfavit);

    cout << "\n";
    decrypted_text = decrypted_text_func(encrypted_text_vector, key_vector, alfavit, Original_text, key);


    file_name = "desencryption_" + file_name;

    File_write(decrypted_text, file_name);
}





void Preparation_for_cipher_polybius_square_encryption(string file_name){
    
    
    string key = getkey_Polybius_Square();
    
    key = DeleteDuplicates(key);
    map <char, string> square;
    
    square_map(key, square);
    
    
    string Original_text = File_read(file_name);
    
    
    string encryption_text = encryption(square,Original_text);
    file_name = "encryption_" + file_name;

    File_write(encryption_text, file_name);
    //string decryption_text = decryption(square,encryption_text);
}




void Preparation_for_cipher_polybius_square_desencryption(string file_name){
    
    
    string key = getkey_Polybius_Square();
    
    key = DeleteDuplicates(key);
    map <char, string> square;
    
    square_map(key, square);
    
    
    string Original_text = File_read(file_name);
    
    
   // string encryption_text = encryption(square,Original_text);
    string decryption_text = decryption(square,Original_text);
    file_name = "desencryption_" + file_name;

    File_write(decryption_text, file_name);

}


