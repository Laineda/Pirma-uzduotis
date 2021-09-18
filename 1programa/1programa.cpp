#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
    string vardas, pavarde;
    float nd[10]{};
    float egzaminas;
}; 

void pild(studentas &kint);
void print(studentas &kin);

int main()
{
    studentas studentai[5];
    for (int i = 0; i < 5; i++)
        pild(studentai[i]);
    for (int i = 0; i < 5; i++)
        print(studentai[i]);
}

void pild(studentas& kint) {
    int n;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vardas >>kint.pavarde;
    cout << "Iveskite namu darbu kieki (1-10): "; cin >> n;
    cout << "Iveskite namu darbu pazymius: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i]; 
    }
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egzaminas;
}

void print(studentas& kin) {
    cout << kin.vardas << " " << kin.pavarde << " ";
    for (int i = 0; i < (sizeof(kin.nd) / sizeof(kin.nd[0])); i++)
        cout << kin.nd[i] << " ";
    cout << "Egzaminas: " << kin.egzaminas << endl;
}

