#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> 
#include <sstream>
#include <iterator>


using namespace std;
struct studentas {
    string vardas, pavarde;
    vector <double> nd;
    double egzaminas;
    double vidurkis;
    double mediana;
    double galutinismed;
    double galutinisvid;
};


unsigned int zdz_sk(string const& str) { //skaiciuojami zodziai
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

double vidurkis(vector<double> nd, double sum) {  //vidurkio formule
    double vidurkis = 0;
    double n = nd.size();
    return vidurkis = sum / n;
}

double mediana(vector<double> nd) {   //medianos formule
    size_t size = nd.size();
    if (size == 0) {
        return 0;  // jei tuscias vektorius
    }
    else {
        sort(nd.begin(), nd.end());
        if (size % 2 != 0) {
            return (double)(nd[size / 2]);  //jei nelyginis skaicius 
        }
        else {
            return (double)((nd[(size - 1) / 2]) + (nd[size / 2])) / 2.0;  //jei lyginis
        }
    }
}

bool pagalba(const studentas& lhs, const studentas& rhs)
{
    return lhs.pavarde < rhs.pavarde;
}

void sortas(vector<studentas>& kint)  // rusiavimo funkcija
{
    sort(kint.begin(), kint.end(), pagalba);
}

void skaityk(vector<studentas>& kint, int* sk)  //failo nuskaitymo funkcija
{
    int student_counter = 0;
    int temp;
    double sum = 0;
    ifstream failos;
    string buff;
    failos.open("kursiokai.txt");
    if (failos.is_open())
    {
        getline(failos >> ws, buff);
        *sk = zdz_sk(buff) - 3;
        while (true)
        {

            kint.resize(kint.size() + 1);
            failos >> kint.at(student_counter).vardas;
            if (failos.eof()) { kint.pop_back(); break; }
            failos >> kint.at(student_counter).pavarde;
            sum = 0;
            for (int i = 0; i < *sk; i++) {
                failos >> temp;
                sum += temp;
                kint.at(student_counter).nd.push_back(temp);
            }
            failos >> kint.at(student_counter).egzaminas;

            kint.at(student_counter).galutinismed = kint.at(student_counter).egzaminas * 0.6 + mediana(kint.at(student_counter).nd) * 0.4;
            kint.at(student_counter).galutinisvid = kint.at(student_counter).egzaminas * 0.6 + vidurkis(kint.at(student_counter).nd, sum) * 0.4;
            student_counter++;
        }
    }
    else { cout << "-\n"; }
}

void print(vector<studentas>& kint, int n) { //spausdinimo funkcija 
    ofstream output;
    output.open("rezultatai.txt");
    output << left << setw(22) << "Pavarde" << setw(22) << "Vardas" << setw(22) << "Galutinis(Vid.) / Galutinis(Med.)" << endl;
    output << "-----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < kint.size(); i++) {
        output << fixed << left << setw(22) << kint[i].pavarde << setw(22) << kint[i].vardas;
        output << setw(22) << setprecision(2) << kint[i].galutinisvid << setw(22) << setprecision(2) << kint[i].galutinismed << endl;
    }
    return;
}

int main()
{
    int sk;
    vector <studentas> studentai;
    skaityk(studentai, &sk);
    sortas(studentai);
    print(studentai, sk);
    return 0;
}
 




