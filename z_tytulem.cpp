#include "z_tytulem.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
z_tytulem::z_tytulem(string numer, string wez, string poch, string i, string n, string t, string w, vector<string>& temp) {
	numer_telefonu = numer;
	imie = i;
	nazwisko = n;
	tytul = t;
	wiek = w;
	wezel = wez;
	pochodzenie = poch;
	temp.push_back(numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(imie);
	temp.push_back(nazwisko);
	temp.push_back(tytul);
	temp.push_back(wiek);
	}
z_tytulem::~z_tytulem() {

	}
void z_tytulem::show() {
	cout << "Stworzono obiekt: " << numer_telefonu << endl;
	cout << "Z klasy: " << wezel << endl;
	cout << "Pochodzenie: " << pochodzenie << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Tytul: " << tytul << endl;
	cout << "Wiek: " << wiek << endl;
	}
