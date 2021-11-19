#include "Student_info.h"

using std::domain_error;

int main()
{
    Core* p1 = new Core;
    Core* p2 = new Grad;
    Core s1;
    Grad s2;

    try { p1->grade(); } catch (domain_error e) { }
    try { p1->name(); } catch (domain_error e) { }

    try { p2->grade(); } catch (domain_error e) { }
    try { p2->name(); } catch (domain_error e) { }

    try { s1.grade(); } catch (domain_error e) { }
    try { s1.name(); } catch (domain_error e) { }

    try { s2.grade(); } catch (domain_error e) { }
    try { s2.name(); } catch (domain_error e) { }

    return 0;
}