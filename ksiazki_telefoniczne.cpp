#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
class ksiazki_telefoniczne {
private:
	T nazwa;
protected:
	string numer_telefonu;
public:
	virtual void show() = 0;
};
