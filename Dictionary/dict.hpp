#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Dictionary
{
    string turkce;                              //türkçesi
    string ingilizce;                           //ingilizcesi
};

extern vector<Dictionary> dictionaryDatas;      // global deðiþken

void convertUpper(string& str);
bool wordIsAvailable(string str);
void addWord(Dictionary sozluk, ofstream& dosya);
void showDictionary();
void searchWord(string kelime);