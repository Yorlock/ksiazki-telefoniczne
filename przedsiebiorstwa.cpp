#include "przedsiebiorstwa.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

przedsiebiorstwa::przedsiebiorstwa(string numer, string wez, string poch, string n, string w, string m, string d, vector<string>& temp) {
	polskie::numer_telefonu = numer;
	polskie::nazwa_instytucji = n;
	wojewodztwo = w;
	miasto = m;
	wezel = wez;
	pochodzenie = poch;
	dochod_roczny = d;
	temp.push_back(polskie::numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(polskie::nazwa_instytucji);
	temp.push_back(wojewodztwo);
	temp.push_back(miasto);
	temp.push_back(dochod_roczny);
}

przedsiebiorstwa::przedsiebiorstwa(string numer, string wez, string poch, string n, string i, string naz, string k, string d, vector<string>& temp) {
	zagraniczne::numer_telefonu = numer;
	zagraniczne::nazwa_instytucji = n;
	imie = i;
	nazwisko = naz;
	kraj = k;
	wezel = wez;
	pochodzenie = poch;
	dochod_roczny = d;
	temp.push_back(zagraniczne::numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(zagraniczne::nazwa_instytucji);
	temp.push_back(imie);
	temp.push_back(nazwisko);
	temp.push_back(kraj);
	temp.push_back(dochod_roczny);
}
przedsiebiorstwa::~przedsiebiorstwa() {
}

void  przedsiebiorstwa::show() {
	if (pochodzenie == "polskie") {
		cout << "Stworzono obiekt: " << polskie::numer_telefonu << endl;
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
