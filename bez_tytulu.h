#ifndef BEZ_TYTULU_H
#define BEZ_TYTULU_H


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
    bez_tytulu();
    bez_tytulu(string, string, string, string, string, string);
    string get_numer_telefonu();
    string get_wezel();
    string get_pochodzenie();
    ~bez_tytulu();
    void mod(string nowa_nazwa);
    string getter();
    void przodkowie(vector<string> &dziedziczy);
};

#endif // BEZ_TYTULU_H
