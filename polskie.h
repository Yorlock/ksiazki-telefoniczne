#ifndef POLSKIE_H
#define POLSKIE_H
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
#endif // POLSKIE_H
