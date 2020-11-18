#pragma once
#include "ksiazki_telefoniczne.cpp"
#include "instytucje.h"
class prywatne :
	public instytucje
{
private:
	string nazwa = "prywatne";
protected:
	string imie;
	string nazwisko;
public:
};

