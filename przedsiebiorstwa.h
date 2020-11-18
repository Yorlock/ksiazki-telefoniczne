#pragma once
#include "panstwowe.h"
#include "polskie.h"
#include "instytucje.h"
#include "prywatne.h"
#include "zagraniczne.h"
#include "ksiazki_telefoniczne.cpp"
#include <vector>
class przedsiebiorstwa :
	public polskie, public zagraniczne
{
private:
	string dochod_roczny;
	string wezel;
	string pochodzenie;
protected:
	virtual void show();
public:
	przedsiebiorstwa(string, string, string, string, string, string, string, vector<string>&);
	przedsiebiorstwa(string, string, string, string, string, string, string, string, vector<string>&);
	~przedsiebiorstwa();
};

