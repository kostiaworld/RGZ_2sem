//
//  cipher_Polybius_Square.cpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#include "cipher_Polybius_Square.hpp"


// Функция для преобразования символа в трехзначный код

// Функция для шифрования текста с использованием квадрата Полибия и трехзначного кодирования

string getkey_Polybius_Square(){
    
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



string DeleteDuplicates(string str) {
    for (string::iterator it1 = str.begin(); it1 != str.end(); ++it1) {
        for (string::iterator it2 = it1 + 1; it2 != str.end(); ) {
            if (*it1 == *it2) {
                str.erase(it2);
            }
            else {
                ++it2;
            }
        }
    }
    return str;
}



void square_map(string key, map <char, string> &square){

    //cout << key;
    vector<char> all_sim;
    int row = 0;
    int col = 0;
  //std::map<std::string, int> out = function();
    char ASCII = ' ';
    for (int i = 0; row < 10 and i <key.size(); i++){
        char c1 = key.c_str()[i];
        all_sim.push_back(c1);
        string all = to_string(row) + to_string(col);
        square.insert(make_pair(c1, all));
        col++;
        if (col == 10){
            col = 0;
            row++;
        }
    }
    vector<char>::iterator it;


    int w = 0;

    for (int i = 0; row < 10; i++){
        it = find (all_sim.begin(), all_sim.end(), ASCII);
        if (it != all_sim.end()){
            w++;
            ASCII++;
            
        }else{
            string all = to_string(row) + to_string(col);
            // создаем пару элементов со значением ключ + символ
            square.insert(make_pair(ASCII, all));
            if (ASCII =='~'){
                break;
            }else{
                ASCII++;
                col++;
                if (col == 10){
                    col = 0;
                    row++;
                }
            }
        }

    }
    square.insert(make_pair(static_cast<char>(32), "99"));

}



string encryption(map <char, string> square, string text){
    //вывод значений map
    map <char, string> :: iterator it = square.begin();
    for (int i = 0; it != square.end(); it++, i++) {  // выводим их
       // cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
    }
    //Шифрование текста
    string t = " ";
    for (int i = 0; i < text.size(); i++) {
        char r = text[i];
        t += square.at(r);
       // cout << t;
    }
    //cout << t;
    string encryption_text = " ";
    //cout << "\n––––––––---––--––-----";
    for (char const &c: text){
        encryption_text += square.at(c);
       // cout << t << " ";
    }
   // cout <<"\n";
   // cout << encryption_text;
   // cout << "\n";
    return encryption_text;
    
}
string decryption(map <char, string> square, string text){
    
    string decryption_text = " ";
    for (int i = 1; i < (text.size()) ; i += 2){
        string rete = text.substr(i, 2);
        for (auto& it : square){
            if (it.second == rete){
                decryption_text += it.first;
                //cout << it.first << ' ';
            }
        }
        //cout << rete << " ";
    }
    //cout << "\n";
    //cout << decryption_text;
    return decryption_text;
}
