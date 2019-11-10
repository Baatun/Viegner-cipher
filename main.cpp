#include <iostream>
#include "textInput.cpp"
#include "kasisTest.cpp"
#include "decrypt.cpp"
using namespace std;

int main() {
    TextInput textInput;
    cout << textInput.getStr() << endl;

    KasisTest kasisTest(textInput.getStr());
    kasisTest.test(3); //pocet zhodnych znakov
    //kasisTest.printArr();
    kasisTest.delitelne();
    int odhadHesla = 23; //to je odhad ake dlhe bude heslo to si davam podla toho co mi vide z delitelne

    Decrypt decrypt(textInput.getStr(), odhadHesla);
    decrypt.fillArr(odhadHesla); //naplnenie matice v ktorej kazdy riadok ma rovnaky posun hesla

    for (int riadok = 0; riadok < odhadHesla; ++riadok) {
        decrypt.test(riadok, odhadHesla);
        decrypt.resetCount();
    }

    cout << endl;
    //decrypt.setStr("ISKOAJHKTRYZPEXNJHHXWQW");       //text1
    //decrypt.setStr("XGAFQEGLRSTMJQFLSGPTKETPHI");    //text2
    //decrypt.setStr("KOKVMINTEUSWECLAUXBFSWM");       //text3
    //decrypt.setStr("CTOJQKZPEXPAAWKANWSRBFFSQUREQ"); //text4
    decrypt.decrypt(textInput.getStr());
    cout << "end"  << endl;
    return 0;
}