#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::left;

struct studentas {
    string vardas, pavarde;
    float nd[10]{};
    float egzaminas;
    float galutinis;
}; 

void pild(studentas &kint);
void print(studentas &kin);

int main()
{
    studentas studentai[5];
    for (int i = 0; i < 2; i++)
        pild(studentai[i]);
    for (int i = 0; i < 2; i++)
        print(studentai[i]);
}

void pild(studentas& kint) {
    int n;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vardas >>kint.pavarde;
    cout << "Iveskite namu darbu kieki (1-10): "; cin >> n;
    cout << "Iveskite namu darbu pazymius: "<<endl;
    float sum = 0, vidurkis = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i]; 
        sum += kint.nd[i];
    }
    vidurkis = sum / n;
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egzaminas;
    kint.galutinis = vidurkis * 0.4 + kint.egzaminas*0.6;
}

void print(studentas &kint) {
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << setw(20) << kint.pavarde << setw(20) << kint.vardas;
    cout << setw(20) << setprecision(3) << kint.galutinis << endl;
}

