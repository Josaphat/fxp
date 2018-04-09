#include "fixedpoint.h"

enum { N_FRACT_BITS = 26 };

fxp fxp_from_int(int a)
{
    const fxp ret = {.val = a << N_FRACT_BITS};
    return ret;
}

fxp fxp_from_fl(float f)
{
    const fxp ret = {.val = f * (1 << N_FRACT_BITS)};
    return ret;
}

fxp fxp_from_dbl(double d)
{
    const fxp ret = {.val = d * (1 << N_FRACT_BITS)};
    return ret;
}

float fxp_to_fl(fxp a)
{
    float x = a.val;
    return x / (1 << N_FRACT_BITS);
}

double fxp_to_dbl(fxp a)
{
    double x = a.val;
    return x / (1 << N_FRACT_BITS);
}

fxp fxp_neg(fxp a)
{
    a.val *= -1;
    return a;
}

fxp fxp_mul(fxp a, fxp b)
{
    const fxp ret = {.val = (a.val >> (N_FRACT_BITS / 2))* (b.val >> (N_FRACT_BITS / 2))};
    return ret;
}

fxp fxp_add(fxp a, fxp b)
{
    const fxp ret = {.val = (a.val + b.val) };
    return ret;
}

fxp fxp_sub(fxp a, fxp b)
{
    return fxp_add(a, fxp_neg(b));
}
