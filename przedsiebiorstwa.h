#ifndef PRZEDSIEBIORSTWA_H
#define PRZEDSIEBIORSTWA_H


#pragma once
#include "panstwowe.h"
#include "polskie.h"
#include "instytucje.h"
#include "prywatne.h"
#include "zagraniczne.h"
#include "ksiazki_telefoniczne.cpp"
#include <vector>
class przedsiebiorstwa :
    public polskie, public zagraniczne
{
private:
    string dochod_roczny;
    string wezel;
    string pochodzenie;
protected:
    virtual void show();
public:
    przedsiebiorstwa(string, string, string, string, string, string, string);
    przedsiebiorstwa(string, string, string, string, string, string, string, string);
    string get_numer_telefonu();
    string get_wezel();
    string get_pochodzenie();
    ~przedsiebiorstwa();
    void mod(string nowa_nazwa);
    string getter();
    void przodkowie(vector<string> &dziedziczy);
};
#endif // PRZEDSIEBIORSTWA_H
