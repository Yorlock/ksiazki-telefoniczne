#ifndef PANSTWOWE_H
#define PANSTWOWE_H

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
#endif // PANSTWOWE_H
