#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <fstream>


using namespace std;
struct studentas {
    string vardas, pavarde;
    vector <int> nd;
    float egzaminas;
    float galutinis;
};


int gen_random()
{
    return rand() % 10 + 1;
}

vector<int> auto_marks(int kiek_pazymiu)
{
    vector<int> skaiciai;
    for (int i = 0; i < kiek_pazymiu; i++)
    {
        skaiciai.push_back(gen_random());
    }
    return skaiciai;
}

float sk_galut(vector<int> skaiciai) {
    studentas stud;
    stud.galutinis = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * gen_random();
    return stud.galutinis;
}

int stud_generavimas(vector<int> pazymiai)
{
    int kiekis;
    cout << "Iveskite studentu kieki: " << endl;
    cin >> kiekis;
    string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
    auto start = chrono::high_resolution_clock::now();
    ofstream out_data(pavadinimas);
    vector<int> skaiciai;
    studentas stud;
    out_data << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(Vid.)" << endl;

    for (int s = 1; s <= kiekis; s = s + 1)
    {
        skaiciai = auto_marks(5);
        out_data << setw(20) << "Vardas" + to_string(s) << setw(20) << "Pavarde" + to_string(s) <<
            setw(18) << sk_galut(skaiciai) << endl;
        skaiciai.clear();
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> skirt = end - start;
    cout << "Failo su " + to_string(kiekis) + " studentu kurimas uztruko: " << skirt.count() << " s\n";
    
    return kiekis;
}

void skaitymas(vector<studentas>& stud, int kiekis)
{
    int studentu_sk = 0;
    ifstream failoSkait;
    string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
    string buff;
    failoSkait.open(pavadinimas);
    if (failoSkait.is_open())
    {
        auto start = chrono::high_resolution_clock::now();
        getline(failoSkait >> ws, buff);
        while (studentu_sk < kiekis)
        {
            stud.resize(stud.size() + 1);
            failoSkait >> stud.at(studentu_sk).vardas;
            failoSkait >> stud.at(studentu_sk).pavarde;
            failoSkait >> stud.at(studentu_sk).galutinis;
            studentu_sk++;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> skirt = end - start;
        cout << "Failo su " + to_string(kiekis) + " studentu nuskaitymas uztruko: "  << skirt.count() << " s\n";
    }
}

int main()
{
    vector <int> skaiciai;
    int kiekis = stud_generavimas(skaiciai);
    vector<studentas> studentai;
    skaitymas(studentai, kiekis);
    vector<studentas> kietiakiai;
    vector<studentas> vargsiukai;
    int kiet = 0;
    int varg = 0;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < kiekis; i++)
    {
        float paz = 5.00;
        if (studentai.at(i).galutinis < paz)
        {
            vargsiukai.push_back(studentai.at(i));
            varg++;
        }
    }
    for (int j = 0; j < kiekis; j++)
    {
        float paz = 5.00;
        if (studentai.at(j).galutinis >= paz)
        {
            kietiakiai.push_back(studentai.at(j));
            kiet++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> skirt = end - start;
    cout << to_string(kiekis) + " irasu dalijimo i dvi grupes laikas : " << skirt.count() << " s\n";

    string pav;
    pav = "vargsiukai_" + to_string(kiekis) + ".txt";
    ofstream varg_failas(pav);
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < kiekis; i++)
    {
        float paz = 5.00;
        if (studentai.at(i).galutinis < paz) {
            varg_failas << studentai.at(i).vardas << setw(20) << studentai.at(i).pavarde << setw(18) << studentai.at(i).galutinis << endl;

        }
    }
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> skirt1 = end1 - start1;
    cout << to_string(kiekis) + " irasu vargsiuku irasymo i faila laikas: " << skirt1.count() << " s\n";

    pav = "kietiakiai_" + to_string(kiekis) + ".txt";
    ofstream kiet_failas(pav);
    auto start2 = chrono::high_resolution_clock::now();
    for (int j = 0; j < kiekis; j++) {
        float paz = 5.00;
        if (studentai.at(j).galutinis >= paz) {
            kiet_failas << studentai.at(j).vardas << setw(20) << studentai.at(j).pavarde << setw(18) << studentai.at(j).galutinis << endl;
        }
    }
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> skirt2 = end2 - start2;
    cout << to_string(kiekis) + " irasu keteku irasymo i faila laikas : " << skirt2.count() << " s\n";
}