#pragma once
#include "ksiazki_telefoniczne.cpp"
#include "prywatne.h"
class zagraniczne :
	public prywatne
{
private:
	string nazwa = "zagraniczne";
protected:
	string kraj;
public:
};

