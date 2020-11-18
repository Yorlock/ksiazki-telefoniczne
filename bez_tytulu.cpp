#include "bez_tytulu.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bez_tytulu::bez_tytulu(string numer, string wez, string poch, string i, string n, string w, vector<string>& temp) {
	numer_telefonu = numer;
	wezel = wez;
	pochodzenie = poch;
	imie = i;
	nazwisko = n;
	wiek = w;
	temp.push_back(numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(imie);
	temp.push_back(nazwisko);
	temp.push_back(wiek);
}
bez_tytulu::~bez_tytulu() {
	}

void bez_tytulu::show() {
	cout << "Stworzono obiekt: " << numer_telefonu << endl;
	cout <<"Z klasy: "<< wezel << endl;
	cout <<"Pochodzenie: " << pochodzenie << endl;
	cout <<"Imie: "<< imie << endl;
	cout <<"Nazwisko: "<< nazwisko << endl;
	cout <<"Wiek: "<< wiek << endl;
	}