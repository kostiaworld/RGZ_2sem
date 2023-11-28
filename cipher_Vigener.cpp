//
//  cipher_Vigener.cpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#include "cipher_Vigener.hpp"

string getkey_Vigener(){
    
    string key = "";
    
    bool Exodus = false;
    
    do
    {
        try
        {
            cout << "Введите свой ключ шифрования: ";
            getline(cin, key);
            if (key == "")
            {
                throw runtime_error("Вы ничего не ввели в строку ввода ключа пожалуйста попробуйте еще раз.\n");
            }
            
            Exodus = true;
        }
        catch (const exception& error)
        {
            system("clear");
            cerr << error.what();
        }
        
    } while (Exodus == false);
    return key;
}



void generate_alfavit(map<char, int> &alfavit){
    char ASCII = ' ';
    for (int i = 0; i < 95; i++){
        alfavit.insert(make_pair(ASCII, i));
        if (ASCII == '~'){
            break;
        }else{
            ASCII++;
        }
        
    }
    
}
string generateKey(string Original_text, string key)
{
    long x = Original_text.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == Original_text.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encrypted_text_func(vector<int>&original_text_vector, vector<int>&key_vector, vector<int>&encrypted_text_vector, string Original_text, string key, map<char, int> &alfavit){
    string encrypted_text;
    
    for (char const &y: Original_text){
        original_text_vector.push_back(alfavit.at(y));
    }
    for (char const &r: key){
        key_vector.push_back(alfavit.at(r));
    }

    for (int i = 0; i < Original_text.size(); i++){
        encrypted_text_vector.push_back((original_text_vector[i] + key_vector[i]) % 95);
    }

    for (int i = 0; i < Original_text.size(); i++){
        for (auto& it : alfavit){
            if (it.second == encrypted_text_vector[i]){
                encrypted_text += it.first;
               // cout << it.first << ' ';
               // cout<<" (" << original_text_vector[i] << " + " << key_vector[i] << ") % 95 = " << encrypted_text_vector[i] << " (" << it.first << ") \n";
            }
        }
    }
    
    return encrypted_text;
}

string decrypted_text_func(vector<int>&encrypted_text_vector, vector<int>&key_vector, map<char, int> &alfavit, string Original_text, string key){
    
    for (char const &y: Original_text){
        encrypted_text_vector.push_back(alfavit.at(y));
    }
    
    for (char const &r: key){
        key_vector.push_back(alfavit.at(r));
    }
    
    string decrypted_text;
    
    vector<int>decrypted_text_vector;
    
    for (int i = 0; i < Original_text.size(); i++){
        decrypted_text_vector.push_back((encrypted_text_vector[i] - key_vector[i] + 95) % 95);
        //cout << decrypted_text_vector[i] << " ";
    }
    for (int i = 0; i < Original_text.size(); i++){
        for (auto& it : alfavit){
            if (it.second == decrypted_text_vector[i]){
                decrypted_text += it.first;
              //  cout << it.first << ' ';
            }
        }
    }

    return decrypted_text;
}
