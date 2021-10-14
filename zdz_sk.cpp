#include "zdz_sk.h"
#include "studentas.h"
#include <string>
#include <sstream>

int zdz_sk(std::string const& str) { //skaiciuojami zodziai
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
