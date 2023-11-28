//
//  cipher_Hill.cpp
//  Final_project_cipher
//
//  Created by Константин on 04.10.2023.
//

#include "cipher_Hill.hpp"


int assign_Hill(int (&key_matr)[3][3])
{
    for (int i = 0; i < 3; i++){
        //cout << "Введите " << i << " элемент из 9: \n";
        for (int j = 0; j < 3; j++){
            int e;
            cout << "Введите " << j + 1 << " из " << i + 1 <<  " строки ";
            cin >> e;
            //e = fool_test(e);
            key_matr[i][j] = int(e);
            //cout << key_matr[i][j] << " ";
        }
        cout << "\n";
    }

    int c1 = key_matr[0][0]*(key_matr[1][1]*key_matr[2][2]-key_matr[1][2]*key_matr[2][1]);
    int c2 = key_matr[0][1]*(key_matr[1][0]*key_matr[2][2]-key_matr[1][2]*key_matr[2][0]);
    int c3 = key_matr[0][2]*(key_matr[1][0]*key_matr[2][1]-key_matr[1][1]*key_matr[2][0]);
    int det_key = (c1 - c2 + c3) % 95;

    //проверка
    if (det_key == 0 or det_key % 5 == 0 or  det_key % 19 == 0 or det_key % 95 == 0){
        cout << "Матрица невырождена пожалуйста попробуйте вести заново";
        
        return assign_Hill(key_matr);
        
    }else{
        return det_key;
        
    }
}

int assign_Hill_generete(int (&key_matr)[3][3])
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            key_matr[i][j] = 1 + rand()%99;
           // cout << key_matr[i][j] << " ";
        }
        //cout << "\n";
    }

    int c1 = key_matr[0][0]*(key_matr[1][1]*key_matr[2][2]-key_matr[1][2]*key_matr[2][1]);
    int c2 = key_matr[0][1]*(key_matr[1][0]*key_matr[2][2]-key_matr[1][2]*key_matr[2][0]);
    int c3 = key_matr[0][2]*(key_matr[1][0]*key_matr[2][1]-key_matr[1][1]*key_matr[2][0]);
    int det_key = (c1 - c2 + c3) % 95;

    //проверка
    if (det_key == 0 or det_key % 5 == 0 or  det_key % 19 == 0 or det_key % 95 == 0){
        return assign_Hill_generete(key_matr);
        
    }else{
        return det_key;
        
    }
}




//создаем алфавит для дальнейшего кодирования
void generete_alfavit_Hill(map<char, int> (&alfavit)){
    
    char ASCII = ' ';
    for (int i = 0; i < 95; i++){
        alfavit.insert(make_pair(ASCII, i));
        if (ASCII == '~'){
            break;
        }else{
            ASCII++;
        }
        
    }

    map <char, int> :: iterator it = alfavit.begin();
    for (int i = 0; it != alfavit.end(); it++, i++) {  // выводим их
        //cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
    }
}



string encryption_Hill(map<char, int> alfavit, int (&key_matr)[3][3] ,vector<int> &sum, string text, int &Namber){
    
    vector<int> vec2;
    vector<int> fin;
    
    string encryption_text = "";
    // перевели фразу "Hello, world!546" в числа и записали каждое число в вектор
    for (char const &y: text){
        vec2.push_back(alfavit.at(y));
    }
    // вывели записанную фразу в виде числе на консоль
    for (int i = 0; i < vec2.size(); i++) {
        if (i != 0) {
            //cout << ", ";
        }
        //cout << vec2[i];
    }
    
    // проверили хватет ли символов для кодирования
    //cout << "\n------------------------\n";
    if (vec2.size()%3 == 2){
        Namber = 1;
    }
    if (vec2.size()%3 == 1){
        Namber = 2;
    }
    // если не хватает для трешек добавили два или три символа
    switch (Namber) {
    case 1:
            vec2.push_back(33);
      break;
    case 2:
            vec2.push_back(33);
            vec2.push_back(33);
      break;
    default:
            
            
      break;
    }
    
    // начинаем кодировать сообщение
    int all_sum = 0;
    int i = 0;
    for (int i = 0; i < vec2.size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << vec2[i];
    }
        for (int col = 0; col < 4 and i < vec2.size(); col++) {
            //cout << i << " " << row << " " << col<< " \n";
            for (int row = 0; row < 3; row++){
                //cout << i << " " << row << " " << col<< " \n";
                int t = key_matr[col][row] * vec2[i];
                all_sum = t + all_sum;
                //cout << i << " " << row << " " << col<< " \n  " << t << "\n" ;
                i++;

                
            }
            sum.push_back(all_sum % 95);
            //cout << sum[i];
            all_sum = 0;
            i = i - 3;
            if (col == 2){
                col = -1;
                i = i + 3;
                
            }
            if (i == 20){
                break;
            }

        }
        //cout << "\n";
    for (int i = 0; i < (sum.size()) ; i++){
        for (auto& it : alfavit){
            if (it.second == sum[i]){
                encryption_text += it.first;
                //cout << sum[i] << ", ";
                //cout << it.first << ' ';
            }
        }
        //cout << rete << " ";
    }
    //cout << "\nЗашифрованное сообщение: "<< encryption_text << "\n";

    return encryption_text;
}


int modInverse_Hill(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}




void invertMatrix_Hill(int (&key_matr)[3][3]) {
    int det = (key_matr[0][0] * (key_matr[1][1] * key_matr[2][2] - key_matr[1][2] * key_matr[2][1]) -
               key_matr[0][1] * (key_matr[1][0] * key_matr[2][2] - key_matr[1][2] * key_matr[2][0]) +
               key_matr[0][2] * (key_matr[1][0] * key_matr[2][1] - key_matr[1][1] * key_matr[2][0])) % 95;

    if (det == 0) {
        cout << "Матрица вырожденная, обратной матрицы не существует" << endl;
        return;
    }

    int inv[3][3];
    inv[0][0] = ((key_matr[1][1] * key_matr[2][2] - key_matr[1][2] * key_matr[2][1]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[0][1] = ((key_matr[0][2] * key_matr[2][1] - key_matr[0][1] * key_matr[2][2]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[0][2] = ((key_matr[0][1] * key_matr[1][2] - key_matr[0][2] * key_matr[1][1]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[1][0] = ((key_matr[1][2] * key_matr[2][0] - key_matr[1][0] * key_matr[2][2]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[1][1] = ((key_matr[0][0] * key_matr[2][2] - key_matr[0][2] * key_matr[2][0]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[1][2] = ((key_matr[1][0] * key_matr[0][2] - key_matr[0][0] * key_matr[1][2]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[2][0] = ((key_matr[1][0] * key_matr[2][1] - key_matr[2][0] * key_matr[1][1]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[2][1] = ((key_matr[2][0] * key_matr[0][1] - key_matr[0][0] * key_matr[2][1]) % 95 * modInverse_Hill(det, 95)) % 95;
    inv[2][2] = ((key_matr[0][0] * key_matr[1][1] - key_matr[1][0] * key_matr[0][1]) % 95 * modInverse_Hill(det, 95)) % 95;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (inv[i][j] < 0){
                key_matr[i][j] = inv[i][j] + 95;
            }else{
                key_matr[i][j] = inv[i][j];
            }
        }
    }
}



string desencryption_Hill(map<char, int> alfavit,int (&key_matr)[3][3] ,vector<int> &sum, int &Namber  ){
    
    vector<int> vec2;
    vector<int> fin;
    int i = 0;
    string desencryption_text = "";
    int all_sum = 0;

    
    for (int col = 0; col < 4 and i < sum.size(); col++) {
        //cout << i << " " << row << " " << col<< " \n";
        for (int row = 0; row < 3; row++){
            //cout << i << " " << row << " " << col<< " \n";
            int t = key_matr[col][row] * sum[i];
            all_sum = t + all_sum;
            i++;
            
        }
        fin.push_back(all_sum % 95);
        all_sum = 0;
        i = i - 3;
        if (col == 2){
            col = -1;
            i = i + 3;
        }
        if (i == 20){
            break;
        }
    }
   // cout << "\n";
    for (int i = 0; i < fin.size(); i++) {
        if (i != 0) {
           // cout << ", ";
        }
       // cout << fin[i];
    }
    for (int i = 0; i < fin.size(); i++){
        for (auto& it : alfavit){
            if (it.second == fin[i]){
                desencryption_text += it.first;
                //cout << it.first << ' ';
            }
        }
    }
    if (Namber == 1){
        if (!desencryption_text.empty()) {
            desencryption_text.erase(desencryption_text.size() - 1);
        }
    }
    if (Namber == 2){
        if (!desencryption_text.empty()) {
            desencryption_text.erase(desencryption_text.size() - 2);
        }
    }
    ///cout << "Расшифрованное сообщение: "<< desencryption_text;
    

    return desencryption_text;
}
