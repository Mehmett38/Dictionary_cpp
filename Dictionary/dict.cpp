#include <iostream>
#include "dict.hpp"

using namespace std;

vector<Dictionary> dictionaryDatas;

void convertUpper(string& str)                           // arama i�lemini kolayla�t�rmak i�in b�t�n kelimeleri
{                                                       // b�y��e �evirir
    string temp;
    for (char chr : str)
    {
        temp += toupper(chr);
    }
    str = temp;
}

bool wordIsAvailable(string str)                           // vectorde ayn� kelime var m�?
{
    convertUpper(str);
    for (int i = 0; i < dictionaryDatas.size(); i++)
    {
        if (dictionaryDatas[i].ingilizce == str || dictionaryDatas[i].turkce == str)
        {
            return 1;                                   // e�er varsa 1 d�ner
        }
    }
    return 0;
}

void addWord(Dictionary sozluk, ofstream& dosya) {        // dosyaya ve vector class�na de�er ekleme metodu

    if (!wordIsAvailable(sozluk.ingilizce))
    {
        convertUpper(sozluk.ingilizce);
        convertUpper(sozluk.turkce);
        dictionaryDatas.push_back(sozluk);
        dosya << sozluk.ingilizce << "\t\t" << sozluk.turkce << endl;
        cout << "Kelime eklenmistir." << endl;
    }
    else
    {
        cout << "Bu kelime daha onceden eklenmistir!" << endl;
    }
}

void showDictionary() {
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < dictionaryDatas.size(); i++)        // vector i�erisinde olan b�t�n de�erleri bast�r�r
    {
        cout << setw(8) << left << dictionaryDatas[i].ingilizce << " : " << dictionaryDatas[i].turkce << endl;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
}

void searchWord(string kelime) {                         // vector i�erisinde index index kelime arar
    convertUpper(kelime);
    string satir;
    bool bulundu = false;
    int i = 0;
    for (; i < dictionaryDatas.size(); i++)
    {
        if (kelime == dictionaryDatas[i].ingilizce || kelime == dictionaryDatas[i].turkce)
        {
            bulundu = true;
            break;
        }
    }
    if (bulundu == true)
    {
        cout << dictionaryDatas[i].ingilizce << " : " << dictionaryDatas[i].turkce << endl << endl;
    }
    else
    {
        cout << "Aradaginiz kelime sozlukte bulunmamaktadir!" << endl << endl;;
    }
}