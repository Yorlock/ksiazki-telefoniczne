#pragma once
#include "osoby.h"
#include <vector>
class bez_tytulu :
	public osoby
{
private:
	string wiek;
	string wezel;
	string pochodzenie;
protected:
	virtual void show();
public:
	bez_tytulu(string, string, string, string, string, string, vector<string>&);
	~bez_tytulu();
};

