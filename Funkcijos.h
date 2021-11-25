#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <random>
#include <list>
using namespace std;
struct studentas
{
    string vardas, pavarde;
    vector<int> nd;
    int egzaminas;
    float galutinis;
};

double vidurkis(vector<int> nd);

vector<studentas> stud_generavimas(int kiek);

void vector_dalijimas_1_strategija(vector<studentas> studentai);

void list_dalijimas_1_strategija(list<studentas> studentai);

void vector_dalijimas_2_strategija(vector<studentas> studentai);

void list_dalijimas_2_strategija(list<studentas> studentai);

void testuoti(int kiek);
