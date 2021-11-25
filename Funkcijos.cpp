#include "Funkcijos.h"

using namespace std;

double vidurkis(vector<int> nd)
{
    int suma = 0;
    for (int i : nd)
    {
        suma += i;
    }
    return suma / nd.size();
}

vector<studentas> stud_generavimas(int kiekis)
{
    vector<studentas> studentai;
    for (int i = 0; i < kiekis; i++)
    {
        studentas temp;
        temp.vardas = "Vardas" + to_string(i + 1);
        temp.pavarde = "Pavarde" + to_string(i + 1);
        int ND1 = rand() % 10 + 1;
        int ND2 = rand() % 10 + 1;
        int ND3 = rand() % 10 + 1;
        int ND4 = rand() % 10 + 1;
        int ND5 = rand() % 10 + 1;

        temp.nd.push_back(ND1);
        temp.nd.push_back(ND2);
        temp.nd.push_back(ND3);
        temp.nd.push_back(ND4);
        temp.nd.push_back(ND5);

        temp.egzaminas = rand() % 10 + 1;

        temp.galutinis = 0.4 * vidurkis(temp.nd) + 0.6 * temp.egzaminas;
        studentai.push_back(temp); 
    }
    return studentai;
}

void vector_dalijimas_1_strategija(vector<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> vargsiukai;
    vector<studentas> kietiakiai;
    for (int i = 0; i < dydis; i++)
    {
        studentas stud = studentai[i];
        if (stud.egzaminas < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
        {
            kietiakiai.push_back(stud);
        }


    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " VECTOR dalijimas 1-ja strategija: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void list_dalijimas_1_strategija(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> vargsiukai;
    vector<studentas> kietiakiai;
    for (studentas stud : studentai)
    {
        if (stud.egzaminas < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
        {
            kietiakiai.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " LIST dalijimas 1-ja strategija: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void vector_dalijimas_2_strategija(vector<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> vargsiukai;
    for (studentas stud : studentai)
    {
        if (stud.egzaminas < 5)
        {
            vargsiukai.push_back(stud);
        }

    }
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](studentas stud)
        {
            return stud.egzaminas < 5;
        }), studentai.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " VECTOR dalijimas 2-ja strategija: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void list_dalijimas_2_strategija(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> vargsiukai;
    for (studentas stud : studentai)
    {
        if (stud.egzaminas < 5)
        {
            vargsiukai.push_back(stud);
        }

    }
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](studentas stud)
        {
            return stud.egzaminas < 5;
        }), studentai.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " LIST dalijimas 2-ja strategija: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void testuoti(int kiek)
{
    vector<studentas> studentai_vector = stud_generavimas(kiek);
    list<studentas> studentai_list;
    copy(studentai_vector.begin(), studentai_vector.end(), back_inserter(studentai_list)); 

    vector_dalijimas_1_strategija(studentai_vector);
    list_dalijimas_1_strategija(studentai_list);

    vector_dalijimas_2_strategija(studentai_vector);
    list_dalijimas_2_strategija(studentai_list);
    cout << endl;

}