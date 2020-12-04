#ifndef Z_TYTULEM_H
#define Z_TYTULEM_H

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
    z_tytulem(string, string, string, string, string, string, string);
    string get_numer_telefonu();
    string get_wezel();
    string get_pochodzenie();
    ~z_tytulem();
    void mod(string nowa_nazwa);
    string getter();
    void przodkowie(vector<string> &dziedziczy);
};

#endif // Z_TYTULEM_H
