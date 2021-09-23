#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;
struct studentas {
    string vardas, pavarde;
    vector <double> nd;
    double egzaminas;
    double galutinis;
};


void pildyk(vector<studentas>& kint, int& n) //pildymo funkcija
{
    cout << "Iveskite studentu skaiciu:" << endl;
    cin >> n;
    double sum = 0, laik;
    double vidurkis = 0;
    double mediana = 0;
    for (int i = 0; i < n; i++) {
        kint.push_back(studentas());
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> kint[i].vardas >> kint[i].pavarde;
        cout << "Iveskite studento namu darbu pazymius: ";
        while (cin >> laik)
        {
            kint[i].nd.push_back(laik);
            sum += laik;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        sort(kint[i].nd.begin(), kint[i].nd.end()); //surusiuojame ivestus nd
        if (n % 2 != 0)
        {
            mediana = (double)(kint[i].nd[n / 2]);
        }
        else
        {
            mediana = (double)((kint[i].nd[(n - 1) / 2]) + (kint[i].nd[n / 2])) / 2.0;
        }
        vidurkis = sum / n;
        cout << "Iveskite egzamino pazymi: "; cin >> kint[i].egzaminas;
        int m;
        cout << "Jei norite, jog galutinis pazymys butu skaiciuojamas su vidurkiu iveskite 0, o jei su mediana parasykite 1: "; cin >> m; cout << endl;
        if (m == 0) {
            kint[i].galutinis = 0.4 * vidurkis + 0.6 * kint[i].egzaminas;
        }
        else
        {
            kint[i].galutinis = 0.4 * mediana + 0.6 * kint[i].egzaminas;
        }
    }

}

void print(vector<studentas>& kint, int& n) {
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis(Vid.) / Galutinis(Med.)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(20) << kint[i].pavarde << setw(20) << kint[i].vardas;
        cout << fixed << setw(20) << setprecision(2) << kint[i].galutinis << endl;
    }

}

int main()
{
    int n;
    vector <studentas> studentai;
    pildyk(studentai, n);
    print(studentai, n);
}
 




