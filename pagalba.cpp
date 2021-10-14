#include "pagalba.h"
#include "studentas.h"

bool pagalba(const studentas& lhs, const studentas& rhs)
{
    return lhs.pavarde < rhs.pavarde;
}
