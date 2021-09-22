#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::left;
using std::sort;


struct studentas {
    string vardas, pavarde;
    double nd[10]{};
    double egzaminas;
    double galutinis;
};

void pild(studentas& kint);
void print(studentas& kin);

int main()
{
    studentas studentai[5];
    for (int i = 0; i < 2; i++)
        pild(studentai[i]);
    for (int i = 0; i < 2; i++)
        print(studentai[i]);
}

void pild(studentas& kint) 
{
    int n; 
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek namu darbu bus? (1-10): "; cin >> n; 
    cout << "Iveskite namu darbu pazymius: " << "\n";
    double sum = 0; 
    double vidurkis = 0; 
    double mediana = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum += kint.nd[i];
    }
    sort(kint.nd, kint.nd + n);
    if (n % 2 != 0)
    {
        mediana = (double)kint.nd[n / 2];
    }
    else
    {
        mediana = (double)(kint.nd[(n - 1) / 2] + kint.nd[n / 2]) / 2.0;
    }
    vidurkis = sum / n;
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egzaminas;
    int m; 
    cout << "Jei norite, jog galutinis pazymys butu skaiciuojamas su vidurkiu iveskite 0, o jei su mediana parasykite 1: "; cin >> m; cout << endl;
    if (m == 0) {
        kint.galutinis = 0.4 * vidurkis + 0.6 * kint.egzaminas; 
    }
    else {
        kint.galutinis = 0.4 * mediana + 0.6 * kint.egzaminas;
    }

}

void print(studentas& kint) {
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << setw(20) << kint.pavarde << setw(20) << kint.vardas;
    cout << setw(20) << setprecision(3) << kint.galutinis << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}


