#ifndef USLUGOWE_H
#define USLUGOWE_H

#pragma once
#include "polskie.h"
#include "ksiazki_telefoniczne.cpp"
#include "panstwowe.h"
#include <vector>
class uslugowe :
    public polskie
{
private:
    string rodzaj_biznesu;
    string wezel;
    string pochodzenie;
protected:
    virtual void show();
public:
    uslugowe(string, string, string, string, string, string, string);
    string get_numer_telefonu();
    string get_wezel();
    string get_pochodzenie();
    ~uslugowe();
    void mod(string nowa_nazwa);
    string getter();
    void przodkowie(vector<string> &dziedziczy);
};
#endif // USLUGOWE_H
