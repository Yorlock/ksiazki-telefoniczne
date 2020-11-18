#pragma once
#include "ksiazki_telefoniczne.cpp"
#include "instytucje.h"
class panstwowe :
	public instytucje
{
private:
	string nazwa = "panstwowe";
protected:
	string wojewodztwo;
public:
};

