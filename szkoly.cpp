#include "szkoly.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

szkoly::szkoly(string numer, string wez, string poch, string n, string w, string m, string l, vector<string>& temp){
	numer_telefonu = numer;
	nazwa_instytucji = n;
	wojewodztwo = w;
	miasto = m;
	wezel = wez;
	pochodzenie = poch;
	liczba_uczniow = l;
	temp.push_back(numer_telefonu);
	temp.push_back(wezel);
	temp.push_back(pochodzenie);
	temp.push_back(nazwa_instytucji);
	temp.push_back(wojewodztwo);
	temp.push_back(miasto);
	temp.push_back(liczba_uczniow);
}

szkoly::~szkoly() {
}

void szkoly::show() {
	cout << "Stworzono obiekt: " << numer_telefonu << endl;
	cout << "Z klasy: " << wezel << endl;
	cout << "Pochodzenie: " << pochodzenie << endl;
	cout << "Nazwa instytucji: " << nazwa_instytucji << endl;
	cout << "Wojewodztwo: " << wojewodztwo << endl;
	cout << "Miasto: " << miasto << endl;
	cout << "Liczba uczniow: " << liczba_uczniow << endl;
}
