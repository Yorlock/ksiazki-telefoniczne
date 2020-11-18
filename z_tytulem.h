#pragma once
#include "osoby.h"
#include <vector>
class z_tytulem :
	public osoby
{
private:
	string tytul;
	string wezel;
	string pochodzenie;
	string wiek;
protected:
	virtual void show();
public:
	z_tytulem(string, string, string, string, string, string, string, vector<string>&);
	~z_tytulem();
};

