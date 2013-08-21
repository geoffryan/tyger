#include <stdio.h>
#include "tyger.h"

int main(int argc, char *argv[])
{
    cow_init(argc, argv, 0);

    int size = 16;
    int ng = 2;
    double a[3] = {-1.0,-1.0,-1.0};
    double b[3] = { 1.0, 1.0, 1.0};

    if(argc > 1)
    {
        size = (int) strtol(argv[1], NULL, 10);
        if(size <= 0)
        {
            printf("Hey, ya gotta give me a positive integer size numbnuts!\n");
            return 0;
        }
    }

    cow_domain *dom = cow_domain_new();
    cow_domain_setndim(dom, 3);
    cow_domain_setsize(dom, 0, size);
    cow_domain_setsize(dom, 1, size);
    cow_domain_setsize(dom, 2, size);
    cow_domain_setextent(dom, 0, a[0], b[0]);
    cow_domain_setextent(dom, 1, a[1], b[1]);
    cow_domain_setextent(dom, 2, a[2], b[2]);
    cow_domain_setguard(dom, ng);
    cow_domain_commit(dom);

    cow_dfield *prim = cow_dfield_new();
    cow_dfield_setdomain(prim, dom);
    cow_dfield_setname(prim, "prim");
    cow_dfield_addmember(prim, "rho");
    cow_dfield_addmember(prim, "vx");
    cow_dfield_addmember(prim, "vy");
    cow_dfield_addmember(prim, "vz");
    cow_dfield_addmember(prim, "P");
    cow_dfield_addmember(prim, "phi");
    cow_dfield_commit(prim);

    cow_dfield *cons = cow_dfield_new();
    cow_dfield_setdomain(cons, dom);
    cow_dfield_setname(cons, "cons");
    cow_dfield_addmember(cons, "rho");
    cow_dfield_addmember(cons, "px");
    cow_dfield_addmember(cons, "py");
    cow_dfield_addmember(cons, "pz");
    cow_dfield_addmember(cons, "E");
    cow_dfield_commit(cons);

    cow_dfield_del(prim);
    cow_dfield_del(cons);
    cow_domain_del(dom);

    cow_finalize();
    return 0;
}
