#include "uslugowe.h"
#include "polskie.h"
#include "ksiazki_telefoniczne.cpp"
#include "panstwowe.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
uslugowe::uslugowe(string numer, string wez, string poch, string n, string w, string m, string r, vector<string>& temp) {
	numer_telefonu = numer;
	nazwa_instytucji = n;
	wojewodztwo = w;
	miasto = m;
	wezel = wez;
	pochodzenie = poch;
	rodzaj_biznesu = r;
	temp.push_back(numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(nazwa_instytucji);
	temp.push_back(wojewodztwo);
	temp.push_back(wojewodztwo);
	temp.push_back(rodzaj_biznesu);
}
uslugowe::~uslugowe() {

}
void uslugowe::show() {
	cout << "Stworzono obiekt: " << numer_telefonu << endl;
	cout << "Z klasy: " << wezel << endl;
	cout << "Pochodzenie: " << pochodzenie << endl;
	cout << "Nazwa instytucji: " << nazwa_instytucji << endl;
	cout << "Wojewodztwo: " << wojewodztwo << endl;
	cout << "Miasto: " << miasto << endl;
	cout << "Rodzaj biznesu: " << rodzaj_biznesu << endl;
}