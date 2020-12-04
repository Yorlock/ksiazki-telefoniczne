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
     virtual string get_numer_telefonu() = 0;
     virtual string get_wezel() = 0;
     virtual string get_pochodzenie() = 0;
     virtual void mod(string nowa_nazwa) = 0;
     virtual string getter() = 0;
     virtual void przodkowie(vector<string>& dziedziczy) = 0;
};
