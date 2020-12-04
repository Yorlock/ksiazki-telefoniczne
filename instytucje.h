#ifndef INSTYTUCJE_H
#define INSTYTUCJE_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "instytucje.cpp"
#include "ksiazki_telefoniczne.cpp"
using namespace std;
class instytucje :
    virtual public ksiazki_telefoniczne <string>
{
private:
    string nazwa = "instytucje";
protected:
    string nazwa_instytucji;
public:
};
#endif // INSTYTUCJE_H
