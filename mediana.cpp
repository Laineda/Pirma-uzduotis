#include "mediana.h"
#include <numeric>
#include <algorithm>

double mediana(std::vector<double> nd) { 
    size_t size = nd.size();
    if (size == 0) {
        return 0;  // jei tuscias vektorius
    }
    else {
        std::sort(nd.begin(), nd.end());
        if (size % 2 != 0) {
            return (double)(nd[size / 2]);  //jei nelyginis skaicius 
        }
        else {
            return (double)((nd[(size - 1) / 2]) + (nd[size / 2])) / 2.0;  //jei lyginis
        }
    }
}
