#include "Student_info.h"
#include "Ptr.h"
#include "compare_Core_ptrs.h"

bool compare_Core_ptrs(const Ptr<Core> cp1, const Ptr<Core> cp2)
{
    return cp1->name() < cp2->name();
}