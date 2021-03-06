/* ID: R_init_L1pack.c, last updated 2020-10-08, F.Osorio */

#include "base.h"
#include "lad.h"
#include <R_ext/Rdynload.h>

#define CALLDEF(name, nargs)  {#name, (DL_FUNC) &name, nargs}
#define F77DEF(name, nargs)   {#name, (DL_FUNC) &F77_NAME(name), nargs}

/* L1 estimation for linear models */
extern void F77_NAME(l1)(int *, int *, int *, int *, double *, double *, double *, double *, double *, int *);
extern void lad_fitter(double *, double *, int *, double *, double *, double *, double *, double *, double *, double *, double *);

/* dpqr-functions for the Laplace distribution */
extern void d_laplace(int *, double *, double *, double *, int *, double *, int *, int *);
extern void p_laplace(int *, double *, double *, double *, int *, double *, int *, int *, int *);
extern void q_laplace(int *, double *, double *, double *, int *, double *, int *, int *, int *);
extern void r_laplace(int *, double *, double *, int *, double *, int *);

/* multivariate Laplace random variate generation */
extern void rand_laplace(double *, int *, double *, double *);

/* registering C and F77 symbols */

static const R_CMethodDef CEntries[]  = {
  CALLDEF(d_laplace,       8),
  CALLDEF(p_laplace,       9),
  CALLDEF(q_laplace,       9),
  CALLDEF(r_laplace,       6),
  CALLDEF(rand_laplace,    4),
  CALLDEF(lad_fitter,     11),
  {NULL, NULL, 0}
};

static const R_FortranMethodDef F77Entries[] = {
  F77DEF(l1,              10),
  {NULL, NULL, 0}
};

void R_init_L1pack(DllInfo *dll)
{
  R_registerRoutines(dll, CEntries, NULL, F77Entries, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
