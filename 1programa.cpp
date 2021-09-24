#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


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
    cin >> n; //studentu skaicius
    char ats;
    double laik;
    double vidurkis = 0;
    double mediana = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        kint.push_back(studentas());
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> kint[i].vardas >> kint[i].pavarde; //irasomas studento vardas ir pavarde

        cout << "Jeigu norite, pazymius irasyti pats, iveskite raide 'p', jei norite automatiskai sugeneruotu, iveskite raide 'a': ";
        cin >> ats; // 'p' arba 'a'
        int x;
        if (ats == 'a') 
        {
            cout << "Namu darbu pazymiai: ";
            for (int j = 0; j < 5; j++) {
                x = rand() % 10 + 1;
                cout << x << " ";
                kint[i].nd.push_back(x); //irasoma i nd masyva
                sum += x;
            }
            cout << endl;

            int random = rand() % 10 + 1;
            cout << "Egzamino pazimys: " << random << endl;
            kint[i].egzaminas = random;
            
        }
        else
        {
            cout << "Iveskite studento namu darbu pazymius: ";
            while (cin >> laik)
            {
                kint[i].nd.push_back(laik); //irasoma i nd masyva
                sum += laik;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Iveskite egzamino pazymi: ";
            cin >> kint[i].egzaminas;
            cout << endl;
           
        }
        cin.clear();
        cin.ignore(10000, '\n');
        sort(kint[i].nd.begin(), kint[i].nd.end()); //surusiuojame ivestus nd
        if (kint[i].nd.size() % 2 != 0)
        {
            mediana = (double)(kint[i].nd[kint[i].nd.size() / 2]); //jei lyginis skaicius kintamuju
        }
        else
        {
            mediana = (double)((kint[i].nd[(kint[i].nd.size() - 1) / 2]) + (kint[i].nd[kint[i].nd.size() / 2])) / 2.0; //jei nelyginis skaicius kintamuju
        }
        vidurkis = sum / kint[i].nd.size(); // skaiciuojamas vidurkis
       
        
    }
    int m;
    cout << "Jei norite, jog galutinis pazymys butu skaiciuojamas su vidurkiu iveskite 0, o jei su mediana parasykite 1: ";
    cin >> m; cout << endl;
    if (m == 0) {
        for (int i = 0; i < kint.size(); i++) 
            kint[i].galutinis = 0.4 * vidurkis + 0.6 * kint[i].egzaminas; //skaiciuojama su vidurkiu  
    }
    else {
        for (int i = 0; i < kint.size(); i++)
            kint[i].galutinis = 0.4 * mediana + 0.6 * kint[i].egzaminas; //skaiciuojama su mediana
    }
}

void print(vector<studentas>& kint, int& n) { //spausdinimo funkcija 
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
    pildyk(studentai, n); //ikvieciamos funkcijos
    print(studentai, n);
}
 




