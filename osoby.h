#pragma once
#include "ksiazki_telefoniczne.cpp"
#include <iostream>
#include <string>
#include <vector>
#include "osoby.cpp"
using namespace std;
class osoby :
	virtual public ksiazki_telefoniczne <string>
{
private:
	string nazwa = "osoby";
protected:
	string imie;
	string nazwisko;
public:
};

