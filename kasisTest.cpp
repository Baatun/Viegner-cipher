//
// Created by samuel on 10/26/19.
//

//
// Created by samuel on 10/26/19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

class KasisTest {
public:
    string sifra;
    vector<int> arr;
    int delitel[1024];

    KasisTest(string str){
        this->sifra = str;
    }

    void test(int pocetZnakov) {   //naplni pole arr hodnotami vzdialenosti rovnakych retazcov
        for (int i = 0; i < sifra.length() - pocetZnakov; ++i) {
            for (int j = i+1; j < sifra.length() - pocetZnakov; ++j) {
                if (duplication(pocetZnakov, i, j))
                    arr.push_back(j - i+1); //vzdialenost medzi poziciami
            }
        }
    }

    bool duplication(int pocetZnakov, int i, int j) { // returne true ak najde rovnaky string
        for (int k = i; k < (i + pocetZnakov); ++k) {
            j++;
            if (sifra[k] == sifra[j])
                continue;
            return false;
        }
        return true;
    }

    void printArr() { //vypis vzdialenosti zhodnych retazcov
        for (auto x : arr)
            std::cout << x << "\n";
    }

    void delitelne() //kazdu vzdialenost deli modulom az po 32 a to ktore je najviac krat delene bezozvysku je nasa odhadovana dlzka helsa
    {
        for (int i = 2; i < 32; i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] % i == 0)
                    delitel[i]++;
            }
        }
        for (int i = 2; i < 32; i++)
        {
            cout << i << " = " << delitel[i];
           // for (int j = 0; j < delitel[i]; ++j) {
           //     cout << "*";
           // };
            cout << endl;
        }
    }

};
