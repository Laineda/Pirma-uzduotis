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
    auto pr = start;
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
        auto st = start;
        getline(failoSkait >> ws, buff);
        while (studentu_sk < kiekis)
        {
            stud.resize(stud.size() + 1);
            failoSkait >> stud.at(studentu_sk).vardas;
            failoSkait >> stud.at(studentu_sk).pavarde;
            failoSkait >> stud.at(studentu_sk).galutinis;
            studentu_sk++;
        }
    }
}

int main()
{
    vector <int> skaiciai;
    int kiekis = stud_generavimas(skaiciai);
    vector<studentas> studentai;
    skaitymas(studentai, kiekis);

}