#include <R_ext/Rdynload.h>
#include "lad.h"
#include "random.h"

static const R_CMethodDef CEntries[]  = {
    {"lad",             (DL_FUNC) &lad,             11},
    {"rand_laplace",    (DL_FUNC) &rand_laplace,    4},
    {NULL, NULL, 0}
};

static const R_FortranMethodDef FortEntries[] = {
    {"l1",          (DL_FUNC) &F77_NAME(l1), 10},
    {NULL, NULL, 0}
};

void R_init_heavy(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, FortEntries, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
