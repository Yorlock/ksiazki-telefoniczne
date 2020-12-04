#include "uslugowe.h"
#include "polskie.h"
#include "ksiazki_telefoniczne.cpp"
#include "panstwowe.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
uslugowe::uslugowe(string numer, string wez, string poch, string n, string w, string m, string r) {
    numer_telefonu = numer;
    nazwa_instytucji = n;
    wojewodztwo = w;
    miasto = m;
    wezel = wez;
    pochodzenie = poch;
    rodzaj_biznesu = r;
}
uslugowe::~uslugowe() {

}
void uslugowe::show() {
    cout << "Obiekt: " << numer_telefonu << endl;
    cout << "Z klasy: " << wezel << endl;
    cout << "Pochodzenie: " << pochodzenie << endl;
    cout << "Nazwa instytucji: " << nazwa_instytucji << endl;
    cout << "Wojewodztwo: " << wojewodztwo << endl;
    cout << "Miasto: " << miasto << endl;
    cout << "Rodzaj biznesu: " << rodzaj_biznesu << endl;
}
string uslugowe::get_numer_telefonu(){
    return numer_telefonu;
}
string uslugowe::get_wezel(){
    return wezel;
}
string uslugowe::get_pochodzenie(){
    return pochodzenie;
}
void uslugowe::mod(string nowa_nazwa){
    string nowe = "";
    numer_telefonu = nowa_nazwa;

    cout << "Obecny: " << nazwa_instytucji << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    nazwa_instytucji = nowe;
    nowe = "";

    cout << "Obecny: " << wojewodztwo << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    wojewodztwo = nowe;
    nowe = "";

    cout << "Obecny: " << miasto << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    miasto = nowe;
    nowe = "";

    cout << "Obecny: " << rodzaj_biznesu << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    rodzaj_biznesu = nowe;
}
string uslugowe::getter(){
    string out = numer_telefonu + " " + wezel + " " + pochodzenie + " " + nazwa_instytucji + " " + wojewodztwo + " " + miasto + " " + rodzaj_biznesu;
    return out;
}
void uslugowe::przodkowie(vector<string> &dziedziczy){
    dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("polskie");
    dziedziczy.push_back("panstwowe"); dziedziczy.push_back("instytucje"); dziedziczy.push_back("uslugowe");
}
