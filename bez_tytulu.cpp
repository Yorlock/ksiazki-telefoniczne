#include "bez_tytulu.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bez_tytulu::bez_tytulu(){}

bez_tytulu::bez_tytulu(string numer, string wez, string poch, string i, string n, string w) {
    numer_telefonu = numer;
    wezel = wez;
    pochodzenie = poch;
    imie = i;
    nazwisko = n;
    wiek = w;
}
bez_tytulu::~bez_tytulu() {
    }

void bez_tytulu::show() {
    cout << "Obiekt: " << numer_telefonu << endl;
    cout <<"Z klasy: "<< wezel << endl;
    cout <<"Pochodzenie: " << pochodzenie << endl;
    cout <<"Imie: "<< imie << endl;
    cout <<"Nazwisko: "<< nazwisko << endl;
    cout <<"Wiek: "<< wiek << endl;
    }
string bez_tytulu::get_numer_telefonu(){
    return numer_telefonu;
}
string bez_tytulu::get_wezel(){
    return wezel;
}
string bez_tytulu::get_pochodzenie(){
    return pochodzenie;
}
void bez_tytulu::mod(string nowa_nazwa){
    string nowe = "";
    numer_telefonu = nowa_nazwa;

    cout << "Obecny: " << imie << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    imie = nowe;
    nowe = "";

    cout << "Obecny: " << nazwisko << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    nazwisko = nowe;
    nowe = "";

    cout << "Obecny: " << wiek << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    wiek = nowe;
}
string bez_tytulu::getter(){
    return this->numer_telefonu + " " + this->wezel + " " + this->pochodzenie + " " + this->imie + " " + this->nazwisko + " " + this->wiek;
}
void bez_tytulu::przodkowie(vector<string> &dziedziczy){
    dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("osoby"); dziedziczy.push_back("bez_tytulu");
}
