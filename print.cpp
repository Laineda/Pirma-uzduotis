#include <fstream> 
#include <iostream>    
#include <iomanip>  
#include "print.h"
#include "skaityk.h"

void print(std::vector<studentas>& kint, int n) {
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::left << std::setw(22) << "Pavarde" << std::setw(22) << "Vardas" << std::setw(22) << "Galutinis(Vid.) / Galutinis(Med.)" << std::endl;
    output << "-----------------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < kint.size(); i++) {
        output << std::fixed << std::left << std::setw(22) << kint[i].pavarde << std::setw(22) << kint[i].vardas;
        output << std::setw(22) << std::setprecision(2) << kint[i].galutinisvid << std::setw(22) << std::setprecision(2) << kint[i].galutinismed << std::endl;
    }
    return;
}
