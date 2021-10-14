#include "sortas.h"
#include "pagalba.h"
#include <numeric>
#include <algorithm>

void sortas(std::vector<studentas>& kint)  
{
    sort(kint.begin(), kint.end(), pagalba);
}

