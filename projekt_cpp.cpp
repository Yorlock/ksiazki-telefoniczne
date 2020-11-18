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
template <typename H> ostream& operator<<(ostream& wyjscie, const vector<H>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            wyjscie << vector[i] << endl;
        }
        else {
            wyjscie << vector[i] << ", ";
        }
    }
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
    transform(str.begin(), str.end(), str.begin(), ::toupper); // 1 arg - poczatek, 2 arg - koniec, 3 arg - odkad zmieniamy, 4 arg - w co zmieniamy
}
void to_lower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower); // 1 arg - poczatek, 2 arg - koniec, 3 arg - odkad zmieniamy, 4 arg - w co zmieniamy
}
bool istnieje_obiekt(string nazwa_obiektu, vector<vector<string>> lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i][0] == nazwa_obiektu) {
            return true;
        }
    }
    return false;
}
void usun_obiekt(string nazwa_obiektu, string wezel, string poprzednie, vector<vector<string>>& lista) {
    bool usunalem = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i][0] == nazwa_obiektu and lista[i][1] == wezel and lista[i][2] == poprzednie) {
            lista.erase(lista.begin() + i);
            usunalem = true;
            cout << "Usunieto obiekt." << endl;
            break;
        }
    }
    if (!(usunalem)) {
        cout << "Jestes w nieodpowiednim wezle by usunac ten obiekt, badz obiekt ma innego potomka." << endl;
    }
}
void show(string nazwa_obiektu, vector<vector<string>>& lista){
    bool jest_taki_obiekt = false;
    for (int i = 0; i < lista.size(); i++) {
        if (nazwa_obiektu == lista[i][0]) {
            cout << lista[i];
            jest_taki_obiekt = true;
            break;
        }
    }
    if (!(jest_taki_obiekt)) {
        cout << "Nie znaleziono takiego obiektu." << endl;
    }
}
void dir(string wezel, string poprzednie, vector<vector<string>>& lista) {
    bool wypisano_cos = false;
    for (int i = 0; i < lista.size(); i++) {
        if (wezel == lista[i][1] or wezel == lista[i][2]) {
            cout << lista[i];
            wypisano_cos = true;
        }
    }
    if (!(wypisano_cos)) {
        cout << "Nie znaleziono zadnego obiektu." << endl;
    }
}
void mod(string nazwa_obiektu, string wezel, vector<vector<string>>& lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (nazwa_obiektu == lista[i][0] and wezel == lista[i][1]) {
            int j = 3;
            string nowe;
            while (j < lista[i].size()) {
                cout << "Obecnie: " << lista[i][j] << endl;
                nowe = "";
                do {
                    cout << "Nowe: "; getline(cin, nowe); cout << endl;
                } while (nowe == "");
                lista[i][j] = nowe;
                j++;
            }
            break;
        }
        else {
            cout << "Nie istnieje taki obiekt w tym wezle." << endl;
        }

    }
    cout << "Zmodyfikowano obiekt." << endl;
    show(nazwa_obiektu, lista);
    //fflush(stdin);
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
void save(vector<vector<string>>& lista){
    fstream plik;
    string nazwa_pliku;
    cout << "Podaj sciezke do pliku: "; getline(cin, nazwa_pliku); cout << endl;
    plik.open(nazwa_pliku, ios::out);
    for (int i = 0; i < lista.size(); i++) {
        plik << i + 1 <<". " << lista[i];
    }
    plik.close();
    cout << "Zapisano obiekty do pliku: " << nazwa_pliku << endl;
}
void read(vector<vector<string>>& lista){
    fstream plik;
    string nazwa_pliku;
    do {
        cout << "Podaj sciezke do pliku: "; getline(cin, nazwa_pliku); cout << endl;
        plik.open(nazwa_pliku, ios::in);
        if (plik.good() == false) {
            cout << "Nie istnieje taki plik." << endl;
        }
    } while (plik.good() == false);
    string linia;
    while (getline(plik, linia)) {
        cout << linia << endl;
    }
    plik.close();
    cout << "Odczytano obiekty z pliku: " << nazwa_pliku << endl;
}
template<class T> bool cd(T obecny, hierarchia<T> klasa, T mozenowy){
    if (obecny != klasa.nazwa) {
        return false;
    }
    else {
        for (int i = 0; i < klasa.polaczenie_potomki.size(); i++) {
            if (mozenowy == klasa.polaczenie_potomki[i]) {
                return true;
            }
        }
        for (int i = 0; i < klasa.polaczenie_przodki.size(); i++) {
            if (mozenowy == klasa.polaczenie_przodki[i]) {
                return true;
            }
        }
    }
    return false;
}
ksiazki_telefoniczne<string>* header;
int main() {
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
    vector <vector <string>> lista;
    int liczba_obiektow = 0;
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
            bool tworz_obiekt = true;
            if (slowa.size() < 2) {
                cout << "Funcja przyjmuje conajmniej 2 argumenty." << endl;
            }
            else if (istnieje_obiekt(slowa[1], lista)) {
                cout << "Istnieje obiekt o takiej nazwie." << endl;
            }
            else {
                vector <string> temp;
                if (wezel == "bez_tytulu") {
                    bez_tytulu obiekt_bez_tytulu(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[4], temp);
                    header = &obiekt_bez_tytulu;
                    header->show();
                }
                else if (wezel == "z_tytulem") {
                    z_tytulem obiekt_z_tytulem(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[3], slowa[4], temp);
                    header = &obiekt_z_tytulem;
                    header->show();
                }
                else if (wezel == "uslugowe") {
                    uslugowe obiekt_uslugowe(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[4], slowa[5], temp);
                    header = &obiekt_uslugowe;
                    header->show();
                }
                else if (wezel == "szkoly") {
                    szkoly obiekt_szkoly(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[4], slowa[5], temp);
                    header = &obiekt_szkoly;
                    header->show();
                }
                else if (wezel == "przedsiebiorstwa" and poprzednie == "polskie") {
                    przedsiebiorstwa obiekt_polskie(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[4], slowa[5], temp);
                    header = &obiekt_polskie;
                    header->show();
                }
                else if (wezel == "przedsiebiorstwa" and poprzednie == "zagraniczne") {
                    przedsiebiorstwa obiekt_zagraniczne(slowa[1], wezel, poprzednie, slowa[2], slowa[3], slowa[4], slowa[5], slowa[6], temp);
                    header = &obiekt_zagraniczne;
                    header->show();
                }
                else {
                    cout << "Nie jestes w liscie." << endl;
                    tworz_obiekt = false;
                }
                if (tworz_obiekt) {
                    lista.push_back(temp);
                    liczba_obiektow++;
                }
            }
        }
        else if (slowa[0] == "DO") {
            if (slowa.size() != 2) {
                cout << "Funcja przyjmuje 2 argumenty." << endl;
            }
            else if ((istnieje_obiekt(slowa[1], lista))) {
                usun_obiekt(slowa[1], wezel, poprzednie, lista);
                liczba_obiektow--;
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
                dir(wezel, poprzednie, lista);
            }
        }
        else if (slowa[0] == "SHOW") {
            if (slowa.size() != 2 or liczba_obiektow == 0) {
                cout << "Nie istnieje zaden obiekt badz zla liczba argumentow." << endl;
            }
            else {
                show(slowa[1], lista);
            }
        }
        else if (slowa[0] == "SAVE") {
        if (slowa.size() != 1) {
            cout << "Funcja nie przyjmuje argumentow." << endl;
        }
        else {
            save(lista);
        }
        }
        else if (slowa[0] == "READ") {
        if (slowa.size() != 1) {
            cout << "Funcja nie przyjmuje argumentow." << endl;
        }
        else {
            read(lista);
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
