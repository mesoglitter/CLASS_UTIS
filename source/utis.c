
#include <math.h>

#include "utis.h"

/* =========================================================
   UTIS phase geometry
   ========================================================= */

double utis_theta(
    struct background *pba,
    double a,
    double k
){

    double A  = pba->A_theta_utis;
    double n  = pba->n_theta_utis;
    double kc = pba->k_c_override_utis;

    double k2  = k*k;
    double kc2 = kc*kc;

    return A * pow(a,n) * (k2/(k2+kc2));
}

/* =========================================================
   matter gravity response
   ========================================================= */

double utis_mu_m(
    struct background *pba,
    double a,
    double k
){

    double theta = utis_theta(pba,a,k);

    return cos(theta)*cos(theta);
}

/* =========================================================
   light/lensing response
   ========================================================= */

double utis_sigma_l(
    struct background *pba,
    double a,
    double k
){

    return 1.0;
}

/* =========================================================
   reserved future background extensions
   ========================================================= */

double utis_F(
    struct background *pba,
    double theta
){

    return 1.0;
}

double utis_V(
    struct background *pba,
    double theta
){

    return 0.0;
}
