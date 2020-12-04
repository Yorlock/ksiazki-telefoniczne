#include "szkoly.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

szkoly::szkoly(string numer, string wez, string poch, string n, string w, string m, string l){
    numer_telefonu = numer;
    nazwa_instytucji = n;
    wojewodztwo = w;
    miasto = m;
    wezel = wez;
    pochodzenie = poch;
    liczba_uczniow = l;
}

szkoly::~szkoly() {
}

void szkoly::show() {
    cout << "Obiekt: " << numer_telefonu << endl;
    cout << "Z klasy: " << wezel << endl;
    cout << "Pochodzenie: " << pochodzenie << endl;
    cout << "Nazwa instytucji: " << nazwa_instytucji << endl;
    cout << "Wojewodztwo: " << wojewodztwo << endl;
    cout << "Miasto: " << miasto << endl;
    cout << "Liczba uczniow: " << liczba_uczniow << endl;
}
string szkoly::get_numer_telefonu(){
    return numer_telefonu;
}
string szkoly::get_wezel(){
    return wezel;
}
string szkoly::get_pochodzenie(){
    return pochodzenie;
}
void szkoly::mod(string nowa_nazwa){
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

    cout << "Obecny: " << liczba_uczniow << endl;
    do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
    liczba_uczniow = nowe;
}
string szkoly::getter(){
    string out = numer_telefonu + " " + wezel + " " + pochodzenie + " " + nazwa_instytucji + " " + wojewodztwo + " " + miasto + " " + liczba_uczniow;
    return out;
}
void szkoly::przodkowie(vector<string> &dziedziczy){
    dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("polskie");
    dziedziczy.push_back("panstwowe"); dziedziczy.push_back("instytucje"); dziedziczy.push_back("szkoly");
}
