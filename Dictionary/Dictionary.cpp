#include <iostream>
#include "dict.hpp"

using namespace std;

int main() {
    ofstream oFile("sozluk.txt", ios::app);                 // dosya yazma
    ifstream iFile("sozluk.txt");                           // dosya okuma

    int choice;
    string lineData, word;
    Dictionary dictionary;
        
    if (iFile.is_open())
    {
        while (getline(iFile, lineData))                  //sat�r sat�r okuma yapar
        {
            std::istringstream iss(lineData);           //okunan sat�rlar� kelimelere �evirir
            iss >> dictionary.ingilizce;                    //kelimeleri uygun de�i�kene atama
            iss >> dictionary.turkce;
            dictionaryDatas.push_back(dictionary);              //s�zl��e ekler
        }
    }

    while (true) {
        cout << "1. Sozluge kelime ekle" << endl;
        cout << "2. Sozlugu goruntule" << endl;
        cout << "3. Kelime ara" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi yapin: ";
        cin >> choice;
        cout << endl << endl;

        if (choice == 1) {                               //kelimeleri al�r ve ekler
            cout << "Ingilizce Kelime : ";
            cin >> dictionary.ingilizce;
            cout << "Turkce Anlami : ";
            cin >> dictionary.turkce;
            addWord(dictionary, oFile);
            cout << endl << endl;
        }
        else if (choice == 2) {
            showDictionary();
        }
        else if (choice == 3) {
            cout << "Kelime: ";
            cin >> word;
            searchWord(word);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    }

    oFile.close();
    iFile.close();

    return 0;
}