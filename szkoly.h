#ifndef SZKOLY_H
#define SZKOLY_H

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
    szkoly(string, string, string, string, string, string, string);
    string get_numer_telefonu();
    string get_wezel();
    string get_pochodzenie();
    ~szkoly();
    void mod(string nowa_nazwa);
    string getter();
    void przodkowie(vector<string> &dziedziczy);
};
#endif // SZKOLY_H
