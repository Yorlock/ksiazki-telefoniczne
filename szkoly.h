#pragma once
#include "polskie.h"
#include <vector>
class szkoly :
	public polskie
{
private:
	string liczba_uczniow;
	string wezel;
	string pochodzenie;
protected:
	virtual void show();
public:
	szkoly(string, string, string, string, string, string, string, vector <string>&);
	~szkoly();
};

