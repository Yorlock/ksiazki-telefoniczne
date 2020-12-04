#include "z_tytulem.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
z_tytulem::z_tytulem(string numer, string wez, string poch, string i, string n, string t, string w) {
    numer_telefonu = numer;
    imie = i;
    nazwisko = n;
    tytul = t;
    wiek = w;
    wezel = wez;
    pochodzenie = poch;
    }
z_tytulem::~z_tytulem() {

    }
void z_tytulem::show() {
    cout << "Obiekt: " << numer_telefonu << endl;
    cout << "Z klasy: " << wezel << endl;
    cout << "Pochodzenie: " << pochodzenie << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Tytul: " << tytul << endl;
    cout << "Wiek: " << wiek << endl;
    }
string z_tytulem::get_numer_telefonu(){
    return numer_telefonu;
}
string z_tytulem::get_wezel(){
    return wezel;
}
string z_tytulem::get_pochodzenie(){
    return pochodzenie;
}
void z_tytulem::mod(string nowa_nazwa){
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

    cout << "Obecny: " << tytul << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    tytul = nowe;
    nowe = "";

    cout << "Obecny: " << wiek << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    wiek = nowe;
}
string z_tytulem::getter(){
    string out = numer_telefonu + " " + wezel + " " + pochodzenie + " " + imie + " " + nazwisko + " " + tytul + " " + wiek;
    return out;
}
void z_tytulem::przodkowie(vector<string> &dziedziczy){
    dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("osoby"); dziedziczy.push_back("z_tytulem");
}
