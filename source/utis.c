
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
   mu(k,a) = 1 - s0 a^n k^2/(k^2+kc^2)
   ========================================================= */

double utis_mu_m(
    struct background *pba,
    double a,
    double k
){

    if (pba->has_utis == _FALSE_) {
        return 1.0;
    }

    double s0 = pba->utis_s0;
    double n  = pba->n_theta_utis;
    double kc = pba->utis_kc;

    double k2  = k*k;
    double kc2 = kc*kc;

    return 1.0 - s0 * pow(a,n) * (k2/(k2+kc2));
}

/* =========================================================
   light/lensing response
   Sigma(k,a) = 1 - sigma0 a^n k^2/(k^2+kc^2)
   ========================================================= */

double utis_sigma_l(
    struct background *pba,
    double a,
    double k
){

    if (pba->has_utis == _FALSE_) {
        return 1.0;
    }

    double sigma0 = pba->utis_sigma0;
    double n      = pba->n_theta_utis;
    double kc     = pba->utis_kc;

    double k2  = k*k;
    double kc2 = kc*kc;

    return 1.0 - sigma0 * pow(a,n) * (k2/(k2+kc2));
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
