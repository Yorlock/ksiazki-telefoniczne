#pragma once
#include "polskie.h"
#include "ksiazki_telefoniczne.cpp"
#include "panstwowe.h"
#include <vector>
class uslugowe :
	public polskie
{
private:
	string rodzaj_biznesu;
	string wezel;
	string pochodzenie;
protected:
	virtual void show();
public:
	uslugowe(string, string, string, string, string, string, string, vector<string>&);
	~uslugowe();
};

