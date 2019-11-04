#include <iostream>
#include "textInput.cpp"
#include "kasisTest.cpp"
#include "decrypt.cpp"
using namespace std;

int main() {
    TextInput textInput; //nacitanie inputu z textoveho suboru
    cout << textInput.getStr() << endl; //vypis nacitaneho textu
    KasisTest kasisTest(textInput.getStr()); //nacitanie inputu do kassiskeho testu
    kasisTest.test(3);
    kasisTest.printArr();
    kasisTest.delitelne();
    int valP = 26; //to je odhad ake dlhe bude heslo to si davam podla toho co mi vide z delitelne
    Decrypt decrypt(textInput.getStr(), valP);
    decrypt.fillArr(valP);

    for (int i = 0; i < valP; ++i) {
        decrypt.test(i, valP);
        decrypt.resetCount();
    }

    cout << endl;
    decrypt.decrypt(textInput.getStr());
    cout << "end"  << endl;
    return 0;
}