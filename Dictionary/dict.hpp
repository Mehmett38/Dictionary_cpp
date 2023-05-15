#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Dictionary
{
    string turkce;                              //t�rk�esi
    string ingilizce;                           //ingilizcesi
};

extern vector<Dictionary> dictionaryDatas;      // global de�i�ken

void convertUpper(string& str);
bool wordIsAvailable(string str);
void addWord(Dictionary sozluk, ofstream& dosya);
void showDictionary();
void searchWord(string kelime);