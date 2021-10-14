#include <iostream>
#include <iomanip>
#include <vector>
#include "skaityk.h"
#include "print.h"
#include "sortas.h"


using namespace std;

int main()
{
    int sk;
    vector <studentas> studentai;
    skaityk(studentai, &sk);
    sortas(studentai);
    print(studentai, sk);
    return 0;
}

 




