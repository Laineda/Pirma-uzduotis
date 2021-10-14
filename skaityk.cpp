#include <iostream>
#include "skaityk.h"
#include "mediana.h"
#include "vidurkis.h"
#include "zdz_sk.h"
#include <string>
#include <fstream> 

void skaityk(std::vector<studentas>& kint, int* sk) 
{
    int student_counter = 0;
    int temp;
    double sum = 0;
    std::ifstream failos;
    std::string buff;
    failos.open("studentai10000.txt.txt");
    if (failos.is_open())
    {
        std::getline(failos >> std::ws, buff);
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
    else { std::cout << "-\n"; }
}
