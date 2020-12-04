#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "ksiazki_telefoniczne.cpp"
#include "osoby.h"
#include "z_tytulem.h"
#include "bez_tytulu.h"
#include "instytucje.h"
#include "panstwowe.h"
#include "prywatne.h"
#include "polskie.h"
#include "zagraniczne.h"
#include "uslugowe.h"
#include "szkoly.h"
#include "przedsiebiorstwa.h"
using namespace std;
const int n = 12;
template<class T> struct hierarchia {
    T nazwa;
    vector<T> polaczenie_potomki;
    vector<T> polaczenie_przodki;
};
ostream& operator<<(ostream& wyjscie, ksiazki_telefoniczne<string>* obj) {
    wyjscie << obj->getter() << endl;
    return wyjscie;
}
void help(){
    cout << " KOMENDY:" << endl;
    cout << " CD [nazwa wezla(klasy)] - zmiana wezla w strukturze" << endl;
    cout << " MO [obiekt] - tworzy obiekt podany jako parametr dla biezacego liscia" << endl;
    cout << " DO [obiekt] - usuwa obiekt podany jako parametr dla biezacego liscia" << endl;
    cout << " MDO [obiekt] - modyfikacja obiektu podanego jako parametr dla biezacego liscia" << endl;
    cout << " DIR - wyswietla informacje o obiektach widocznych z danego poziomu" << endl;
    cout << " SHOW [obiekt] - wyswietla szczegolowe informacje o obiekcie" << endl;
    cout << " SAVE [plik]- zapis zbioru do pliku" << endl;
    cout << " READ [plik] - odczyt zbioru z pliku" << endl;
    cout << " TREE - wyswietla cala strukture przedstawiona na rysunku" << endl;
    cout << " EXIT - wyjscie z programu" << endl;
    cout << " HELP - wyswietlenie wszystkich komend" << endl << endl;
    cout << "bez_tytulu - numer_telefonu, imie, nazwisko, wiek" << endl;
    cout << "z_tytulem - numer_telefonu, imie, nazwisko, tytul, wiek" << endl;
    cout << "uslugowe - numer_telefonu, nazwa, wojewodztwo, miasto, rodzaj_biznesu" << endl;
    cout << "szkoly - numer_telefonu, nazwa, wojewodztwo, miasto, liczba_uczniow" << endl;
    cout << "przedsiebiorstwa (polskie) - numer_telefonu, nazwa, wojewodztwo, miasto, dochod_roczny" << endl;
    cout << "przedsiebiorstwa (zagraniczne) - numer_telefonu, nazwa, imie, nazwisko, kraj, dochod_roczny" << endl;
}
void string_into_words(string str, vector<string> &slowa)
{
    string slowo = "";
    for (auto i : str) {
        if (i == ' ') {
            slowa.push_back(slowo);
            slowo = "";
        }
        else {
            slowo = slowo + i;
        }
    }
    slowa.push_back(slowo);
}
void to_upper(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}
void to_lower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}
bool istnieje_obiekt(string nazwa_obiektu, vector <ksiazki_telefoniczne<string>*> &lista) {
    for (unsigned long long i = 0; i < lista.size(); i++) {
        if (lista[i]->get_numer_telefonu() == nazwa_obiektu) {
            return true;
        }
    }
    return false;
}
void usun_obiekt(string nazwa_obiektu, string wezel, string poprzednie, vector <ksiazki_telefoniczne<string>*> &lista) {
    for (unsigned long long i = 0; i < lista.size(); i++) {
        if (lista[i]->get_numer_telefonu() == nazwa_obiektu and lista[i]->get_wezel() == wezel and lista[i]->get_pochodzenie() == poprzednie) {
            lista.erase(lista.begin() + i);
            cout << "Usunieto obiekt." << endl;
            return;
        }
    }
    cout << "Jestes w nieodpowiednim wezle by usunac ten obiekt, badz obiekt ma innego potomka." << endl;
}
void stworz_obiekt(vector<string> slowa, vector <ksiazki_telefoniczne<string>*> &lista){
    ksiazki_telefoniczne<string>* helper;
    if (slowa[slowa.size() - 2] == "bez_tytulu") {
        helper = new bez_tytulu(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[4]);
    }
    else if (slowa[slowa.size() - 2] == "z_tytulem") {
        helper = new z_tytulem(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[3], slowa[4]);
    }
    else if (slowa[slowa.size() - 2] == "uslugowe") {
        helper = new uslugowe(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[4], slowa[5]);
    }
    else if (slowa[slowa.size() - 2] == "szkoly") {
        helper = new szkoly(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[4], slowa[5]);
    }
    else if (slowa[slowa.size() - 2] == "przedsiebiorstwa" and slowa[slowa.size() - 1] == "polskie") {
        helper = new przedsiebiorstwa(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[4], slowa[5]);
    }
    else if (slowa[slowa.size() - 2] == "przedsiebiorstwa" and slowa[slowa.size() - 1] == "zagraniczne") {
        helper = new przedsiebiorstwa(slowa[1], slowa[slowa.size() - 2], slowa[slowa.size() - 1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6]);
    }
    else { cout << "Nie jestes w liscie." << endl; return;}
    lista.emplace_back(helper);
    helper->show();
}
void stworz_obiekt_bez_liscia(vector<string> slowa, vector <ksiazki_telefoniczne<string>*> &lista){
    ksiazki_telefoniczne<string>* helper;
    if (slowa[1] == "bez_tytulu") {
        helper = new bez_tytulu(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5]);
    }
    else if (slowa[1] == "z_tytulem") {
        helper = new z_tytulem(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6]);
    }
    else if (slowa[1] == "uslugowe") {
        helper = new uslugowe(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6]);
    }
    else if (slowa[1] == "szkoly") {
        helper = new szkoly(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6]);
    }
    else if (slowa[1] == "przedsiebiorstwa" and slowa[2] == "polskie") {
        helper = new przedsiebiorstwa(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6]);
    }
    else if (slowa[1] == "przedsiebiorstwa" and slowa[2] == "zagraniczne") {
        helper = new przedsiebiorstwa(slowa[0], slowa[1], slowa[2], slowa[3], slowa[4], slowa[5], slowa[6], slowa[7]);
    }
    else return;
    lista.emplace_back(helper);
}
void show(string nazwa_obiektu, vector <ksiazki_telefoniczne<string>*> &lista){
    for (unsigned long long i = 0; i < lista.size(); i++) {
        if (nazwa_obiektu == lista[i]->get_numer_telefonu()) {
            lista[i]->show();
            return;
        }
    }
    cout << "Nie znaleziono takiego obiektu." << endl;
}
bool dziedziczy_od(string wezel, vector<string> przodkowie){
    for (unsigned long long i = 0; i < przodkowie.size(); i++){
        if (przodkowie[i] == wezel) return true;
    }
    return false;
}
void dir(vector <ksiazki_telefoniczne<string>*> &lista, string wezel) {
    vector<string> dziedziczy;
    dziedziczy.reserve(5);
    for (unsigned long long i = 0; i < lista.size(); i++) {
        lista[i]->przodkowie(dziedziczy);
        if (dziedziczy_od(wezel,dziedziczy)){
            cout << lista[i];
            // cout <<lista[i]->getter() << endl;
        }
        dziedziczy.clear();
    }
}
void mod(string nazwa_obiektu, string wezel, vector <ksiazki_telefoniczne<string>*> &lista) {
    for (unsigned long long i = 0; i < lista.size(); i++) {
        if (nazwa_obiektu == lista[i]->get_numer_telefonu() and wezel == lista[i]->get_wezel()) {
            string nowe;
            cout << "Obecny: " << lista[i]->get_numer_telefonu() << endl;
            do {
                nowe = "";
                cout << "Nowe: ";
                getline(cin, nowe);
                cout << endl;
                if(nowe == "" or istnieje_obiekt(nowe, lista)){
                    cout << "Nie wprowadzono nazwy, badz obiekt o takiej nazwie juz istnieje." << endl;
                }
            } while (nowe == "" or istnieje_obiekt(nowe, lista));
            lista[i]->mod(nowe);
            cout << "Zmodyfikowano obiekt." << endl;
            lista[i]->show();
            return;
        }
    }
    cout << "Nie istnieje taki obiekt w tym wezle." << endl;
}
void tree() {
    cout << "------------------------ksiazki telefoniczne-----------------------------------" << endl;
    cout << "---------------------/---------------------\\-----------------------------------" << endl;
    cout << "-------------------osoby--------------------instytucje-------------------------" << endl;
    cout << "----------------/-------\\-----------------/----------\\-------------------------" << endl;
    cout << "---------bez tytulu---z tytulem-------panstwowe-------prywatne-----------------" << endl;
    cout << "------------------------------------------|-------------|----------------------" << endl;
    cout << "---------------------------------------poskie------zagraniczne-----------------" << endl;
    cout << "-----------------------------------/----|-----\\------|-------------------------" << endl;
    cout << "--------------------------uslugow----szkoly---przedsiebiorstwa-----------------" << endl;
}
void save(vector <ksiazki_telefoniczne<string>*> &lista, string nazwa_pliku){
    fstream plik;
    plik.open(nazwa_pliku, ios::out);
    for (unsigned long long i = 0; i < lista.size(); i++) {
        plik << lista[i]->getter() << endl;
    }
    plik.close();
    cout << "Zapisano obiekty do pliku: " << nazwa_pliku << endl;
}
void read(vector <ksiazki_telefoniczne<string>*> &lista, string nazwa_pliku){
    fstream plik;
    plik.open(nazwa_pliku, ios::in);
    if (plik.good() == false) {
        cout << "Nie istnieje taki plik." << endl;
        do {
            cout << "Podaj sciezke do pliku: "; getline(cin, nazwa_pliku); cout << endl;
            plik.open(nazwa_pliku, ios::in);
            if (plik.good() == false) {
                cout << "Nie istnieje taki plik." << endl;
            }
        } while (plik.good() == false);
    }
    string linia;
    while (getline(plik, linia)) {
        vector<string> slowa;
        // cout << linia << endl;
        string_into_words(linia, slowa);
        if(istnieje_obiekt(slowa[0], lista)) cout <<"Nie stworzono obiektu " << slowa[0] <<", poniewaz juz istnieje."<<endl;
        else stworz_obiekt_bez_liscia(slowa, lista);
    }
    plik.close();
    cout << "Odczytano obiekty z pliku: " << nazwa_pliku << endl;
}
template<class T> bool cd(T obecny, hierarchia<T> klasa, T mozenowy){
    if (obecny != klasa.nazwa) {
        return false;
    }
    else {
        for (unsigned long long i = 0; i < klasa.polaczenie_potomki.size(); i++) {
            if (mozenowy == klasa.polaczenie_potomki[i]) {
                return true;
            }
        }
        for (unsigned long long i = 0; i < klasa.polaczenie_przodki.size(); i++) {
            if (mozenowy == klasa.polaczenie_przodki[i]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    vector <ksiazki_telefoniczne<string>*> lista;
    hierarchia<string> klasy[] = { {"ksiazki_telefoniczne", {"instytucje" , "osoby"},{}}, {"instytucje", {"panstwowe", "prywatne"}, {"ksiazki_telefoniczne"}},
    {"osoby", {"z_tytulem", "bez_tytulu"}, {"ksiazki_telefoniczne"}}, {"z_tytulem", {}, {"osoby"}}, {"bez_tytulu", {}, {"osoby"}},
    {"panstwowe", {"polskie"}, {"instytucje"}}, {"prywatne", {"zagraniczne"}, {"instytucje"}},
    {"polskie", {"uslugowe", "szkoly", "przedsiebiorstwa"}, {"panstwowe"}}, {"zagraniczne", {"przedsiebiorstwa"}, {"prywatne"}},
    {"uslugowe", {}, {"polskie"}}, {"szkoly", {}, {"polskie"}}, {"przedsiebiorstwa", {}, {"polskie", "zagraniczne"}}
    };
    string komenda;
    vector<string> slowa;
    string wezel = "ksiazki_telefoniczne";
    string poprzednie;
    help();
    do {
        do {
            cout << "> "; getline(cin, komenda); cout << endl;
            if (komenda == "") {
                cout << "Brak komendy." << endl;
            }
        } while (komenda == "");
        string_into_words(komenda, slowa);
        to_upper(slowa[0]);
        for_each(slowa.begin() + 1, slowa.end(), to_lower);
        if (slowa[0] == "CD") {
            if (slowa.size() != 2) {
                cout << "Funcja przyjmuje jeden argument (klasa do ktorej ma sie udac)." << endl;
            }
            else {
                for (int i = 0; i < n; i++) {
                    if (cd<string>(wezel, klasy[i], slowa[1])) {
                        poprzednie = wezel;
                        wezel = slowa[1];
                        cout << "Nowy wezel to: " << wezel << endl;
                        cout << "Poprzedni wezel to: " << poprzednie << endl;
                        break;
                    }
                }
                if (wezel != slowa[1]) {
                    cout << "Nie ma takiego wezla." << endl;
                }
            }

        }
        else if (slowa[0] == "MO") {
            if (slowa.size() < 2) {
                cout << "Funcja przyjmuje conajmniej 2 argumenty." << endl;
            }
            else if (istnieje_obiekt(slowa[1], lista)) {
                cout << "Istnieje obiekt o takiej nazwie." << endl;
            } else {
                slowa.push_back(wezel); slowa.push_back(poprzednie);
                stworz_obiekt(slowa, lista);
            }
        }
        else if (slowa[0] == "DO") {
            if (slowa.size() != 2) {
                cout << "Funcja przyjmuje 2 argumenty." << endl;
            }
            else if ((istnieje_obiekt(slowa[1], lista))) {
                usun_obiekt(slowa[1], wezel, poprzednie, lista);
            }
            else {
                cout << "Nie istnieje taki obiekt, badz zostal juz usuniety." << endl;
            }
        }
        else if (slowa[0] == "MDO") {
            if (!(istnieje_obiekt(slowa[1], lista)) or slowa.size() != 2) {
                cout << "Nie istnieje taki obiekt, badz zle wprowadzona komenda." << endl;
            }
            else {
                mod(slowa[1], wezel, lista);
            }
        }
        else if (slowa[0] == "DIR") {
            if (slowa.size() > 1) {
                cout << "Funkcja nie przyjmuje zadnych argumentow" << endl;
            }
            else {
                dir(lista, wezel);
            }
        }
        else if (slowa[0] == "SHOW") {
            if (slowa.size() != 2) {
                cout << "Zla liczba argumentow." << endl;
            }
            else {
                show(slowa[1], lista);
            }
        }
        else if (slowa[0] == "SAVE") {
            if (slowa.size() != 2) {
                cout << "Zla komenda." << endl;
            }
            else {
                save(lista, slowa[1]);
            }
        }
        else if (slowa[0] == "READ") {
            if (slowa.size() != 2) {
                cout << "Zla komenda." << endl;
            }
            else {
                read(lista, slowa[1]);
            }
        }
        else if (slowa[0] == "TREE") {
            if (slowa.size() != 1) {
                cout << "Funcja nie przyjmuje zadnych argumentow." << endl;
            }
            else {
                tree();
            }
        }
        else if (slowa[0] == "EXIT") {
            if (slowa.size() != 1) {
                cout << "Funcja nie przyjmuje zadnych argumentow." << endl;
            }
            else {
                return 0;
            }
        }
        else if (slowa[0] == "HELP") {
            if (slowa.size() != 1) {
                cout << "Funcja nie przyjmuje zadnych argumentow." << endl;
            }
            else {
                help();
            }
        }
        else {
            cout << "Niepoprawna komenda. Sprobuj jeszcze raz" << endl;
        }
        slowa.clear();
    } while (komenda != "EXIT");
    return 0;
}
