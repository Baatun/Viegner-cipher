//
// Created by samuel on 10/26/19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <math.h>
using namespace std;

class Decrypt {
public:

    double sk[26] = {0.11160, 0.01778, 0.02463, 0.03760,
                    0.09316, 0.00165, 0.00175, 0.02482, 0.05745, 0.02158,
                    0.03961, 0.04375, 0.03578, 0.05949, 0.09540, 0.03007,
                    0.00000, 0.04706, 0.06121, 0.05722, 0.03308, 0.04604,
                    0.00001, 0.00028, 0.02674, 0.03064};

    double ang[26] = {0.0856, 0.0139, 0.0279, 0.0378,
                      0.1304, 0.286, 0.0199, 0.0526, 0.0627, 0.0019,
                      0.042, 0.339, 0.0249, 0.0707, 0.0797, 0.0199,
                      0.0012, 0.0977, 0.0607, 0.1045, 0.0249, 0.0092,
                      0.0149, 0.0017, 0.0199, 0.0008 };

    int lines = 0;
    string str;
    string password;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;
    char arr[32][1024];
    double probability[30][1024];
    double difference[27];

    Decrypt(string str, int n) {
        this->lines = n;
        this->str = str;
    }

    void resetCount() {
        count = 0;
    }

    void fillArr(int n) { //naplnam string do matice ktora ma stlpce dlhe ako odhad hesla znakov, kazdy riadok matice ma rovnaky posun
        bool b = false;
        int c = 0;
        for (int i = 0; i < str.length(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (b)
                    return;
                arr[j][i] = str[c];
                c++;
                if (str.length() == c)
                    b = true;
            }
        }
    }

    void coincidenceIndex(int n) { //po ziskani pravdepodobnosti vyskytu znaku porovnavam vyskyt s vyskytom v jazyku
        difference[count] = 0;
        for (int i = 0; i < abc.length(); ++i) { //prechadzam celu abecedu
            difference[count] += pow(probability[n][i] - sk[i],2); //pre kazde pismeno v abecede sa vyrata rodiel a najmensi je to pismeno
        }
        difference[count] = abs(difference[count]); // CO DAVAM DO DIFERENCE COUNT
        count++; //zistujem rozdiel aky mi vysiel ked som ratal pravdepodobnost vyskytu s oficialnym vyskytom pismen v jazyku
    }

    void cesar(int r) {
        for (int i = 0; i < str.length()/lines; ++i) { //tomuto vobec nechapem lines = odhad hesla
            int letter = (int)arr[r][i] + 1;
            char p = (char)letter;
            arr[r][i] = p;
            if (arr[r][i]>90)
                arr[r][i] = 'A';
        }
    }

    void test(int r, int odhadHesla) {
        for (int i = 0; i < 26; ++i) { //26 pocet pismen v abecede pre kazde pismeno aby som mal kombinacie
            pravdepodobnostVyskytu(r, odhadHesla); //pre kazde pismeno vyrata pravdepodobnost vyskytu v texte ????
        }
        printDifference(r); //toto co robi
    }

    void pravdepodobnostVyskytu(int r, int odhadHesla) {
        int count = 0;
        int countR = 0;
        for (int i = 0; i < abc.length(); ++i) {                    //pre kazde pismeno z abecedy
            for (int j = 0; j < str.length() / odhadHesla; ++j) {   //prechadza stringom a zistije pocetnost znaku
                if (arr[r][j] == abc[i]) {
                    count++;
                }
                countR++;                                           //zratavaju sa vsetky znaky aby sa dala vypocitat pravdepodobnost vyskytu
            }
            probability[r][i] = (double)count/(double)countR;       //i = pismeno abecedy r = prvy riadok v hesle
            count = 0;
            countR = 0;
        }
        coincidenceIndex(r);
        cesar(r);
    }

    void printDifference(int r) {
        double min = 9999999999;
        int index = 1000;
        for (int i = 0; i < abc.length(); ++i) {
            if (min>difference[i]) {
                min = difference[i];
                index = i;
            }
        }
        password += (char)((26-index)+65);
        if (index==0) {
            cout << "A";
        }
        cout << (char)((26-index)+65);
    }

    void decrypt(string pom) { // vlozi sa tu povodny zaaheslovany retazec
        int value = 0;
        for (int i = 0; i < pom.length(); ++i) {
            value = (pom[i]+65) - password[i%password.length()];
            if (value < 65)
                value += 26;
            cout << (char)value;
        }
    }

};
