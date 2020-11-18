#pragma once
#include "ksiazki_telefoniczne.cpp"
#include "panstwowe.h"
class polskie :
	public panstwowe
{
private:
	string nazwa = "polskie";
protected:
	string miasto;
public:
};

