#include "przedsiebiorstwa.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

przedsiebiorstwa::przedsiebiorstwa(string numer, string wez, string poch, string n, string w, string m, string d) {
    polskie::numer_telefonu = numer;
    polskie::nazwa_instytucji = n;
    wojewodztwo = w;
    miasto = m;
    wezel = wez;
    pochodzenie = poch;
    dochod_roczny = d;
}

przedsiebiorstwa::przedsiebiorstwa(string numer, string wez, string poch, string n, string i, string naz, string k, string d) {
    zagraniczne::numer_telefonu = numer;
    zagraniczne::nazwa_instytucji = n;
    imie = i;
    nazwisko = naz;
    kraj = k;
    wezel = wez;
    pochodzenie = poch;
    dochod_roczny = d;
}
przedsiebiorstwa::~przedsiebiorstwa() {
}

void  przedsiebiorstwa::show() {
    if (pochodzenie == "polskie") {
        cout << "Obiekt: " << polskie::numer_telefonu << endl;
        cout << "Z klasy: " << wezel << endl;
        cout << "Pochodzenie: " << pochodzenie << endl;
        cout << "Nazwa instytucji: " << polskie::nazwa_instytucji << endl;
        cout << "Wojewodztwo: " << wojewodztwo << endl;
        cout << "Miasto: " << miasto << endl;
        cout << "Dochod roczny: " << dochod_roczny << endl;
    }
    else {
        cout << "Stworzono obiekt: " << zagraniczne::numer_telefonu << endl;
        cout << "Z klasy: " << wezel << endl;
        cout << "Pochodzenie: " << pochodzenie << endl;
        cout << "Nazwa instytucji: " << zagraniczne::nazwa_instytucji << endl;
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Kraj pochodzenia instytucji: " << kraj << endl;
        cout << "Dochod roczny: " << dochod_roczny << endl;
    }
}

string przedsiebiorstwa::get_numer_telefonu(){
    return numer_telefonu;
}
string przedsiebiorstwa::get_wezel(){
    return wezel;
}
string przedsiebiorstwa::get_pochodzenie(){
    return pochodzenie;
}
void przedsiebiorstwa::mod(string nowa_nazwa){
    if (pochodzenie == "polskie") {
        string nowe = "";     
        polskie::numer_telefonu = nowa_nazwa;

        cout << "Obecny: " << polskie::nazwa_instytucji << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        polskie::nazwa_instytucji = nowe;
        nowe = "";

        cout << "Obecny: " << wojewodztwo << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        wojewodztwo = nowe;
        nowe = "";

        cout << "Obecny: " << miasto << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        miasto = nowe;
        nowe = "";

        cout << "Obecny: " << dochod_roczny << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        dochod_roczny = nowe;
    } else {
        string nowe = "";     
        zagraniczne::numer_telefonu = nowa_nazwa;

        cout << "Obecny: " << zagraniczne::nazwa_instytucji << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        zagraniczne::nazwa_instytucji = nowe;
        nowe = "";

        cout << "Obecny: " << imie << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        imie = nowe;
        nowe = "";

        cout << "Obecny: " << nazwisko << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        nazwisko = nowe;
        nowe = "";

        cout << "Obecny: " << kraj << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        kraj = nowe;
        nowe = "";

        cout << "Obecny: " << dochod_roczny << endl;
        do { cout << "Nowe: "; getline(cin, nowe); cout << endl; } while (nowe == "");
        dochod_roczny = nowe;
    }
}
string przedsiebiorstwa::getter(){
    string out = "";
    if (pochodzenie == "polskie") {
        out = polskie::numer_telefonu + " " + wezel + " " + pochodzenie + " " + polskie::nazwa_instytucji + " " + wojewodztwo + " " + miasto + " " + dochod_roczny;
    }
    else {
        out = zagraniczne::numer_telefonu + " " + wezel + " " + pochodzenie + " " + zagraniczne::nazwa_instytucji + " " + imie + " " + nazwisko + " " + kraj + " "+ dochod_roczny;
    }
    return out;
}
void przedsiebiorstwa::przodkowie(vector<string> &dziedziczy){
    if (pochodzenie == "polskie") {
        dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("polskie");
        dziedziczy.push_back("panstwowe"); dziedziczy.push_back("instytucje"); dziedziczy.push_back("przedsiebiorstwa");
    } else {
        dziedziczy.push_back("ksiazki_telefoniczne"); dziedziczy.push_back("instytucje");
        dziedziczy.push_back("prywatne"); dziedziczy.push_back("zagraniczne"); dziedziczy.push_back("przedsiebiorstwa");
    }
}
