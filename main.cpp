#include <iostream>
#include "textInput.cpp"
#include "kasisTest.cpp"
#include "decrypt.cpp"
using namespace std;

int main() {
    TextInput textInput; //nacitanie inputu z textoveho suboru
    cout << textInput.getStr() << endl; //vypis nacitaneho textu
    KasisTest kasisTest(textInput.getStr()); //nacitanie inputu do kassiskeho testu
    kasisTest.test(3); //hlada 3 zhodne znaky
    kasisTest.printArr();
    kasisTest.delitelne();
    int odhadHesla = 23; //to je odhad ake dlhe bude heslo to si davam podla toho co mi vide z delitelne

    Decrypt decrypt(textInput.getStr(), odhadHesla); //konstruktor
    decrypt.fillArr(odhadHesla); //naplnenie matice v ktorej kazdy riadok ma rovnaky posun hesla TOTO

    for (int i = 0; i < odhadHesla; ++i) { //pre kazde pismeno v hesle
        decrypt.test(i, odhadHesla);
        decrypt.resetCount();
    }

    cout << endl;
    decrypt.decrypt(textInput.getStr()); //TOTO
    cout << "end"  << endl;
    return 0;
}