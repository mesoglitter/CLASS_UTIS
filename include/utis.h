
#ifndef __UTIS__
#define __UTIS__

#include "background.h"

/* =========================================================
   UTIS geometry response engine
   ========================================================= */

/* phase geometry */
double utis_theta(
    struct background *pba,
    double a,
    double k
);

/* matter gravity response */
double utis_mu_m(
    struct background *pba,
    double a,
    double k
);

/* light/lensing response */
double utis_sigma_l(
    struct background *pba,
    double a,
    double k
);

/* reserved future background extensions */
double utis_F(
    struct background *pba,
    double theta
);

double utis_V(
    struct background *pba,
    double theta
);

#endif
