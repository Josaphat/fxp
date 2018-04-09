#ifndef FIXEDPOINT_FIXEDPOINT_H
#define FIXEDPOINT_FIXEDPOINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    int32_t val;
} fxp;

fxp fxp_from_int(int a);
fxp fxp_from_fl(float f);
fxp fxp_from_dbl(double d);

float fxp_to_fl(fxp a);
double fxp_to_dbl(fxp a);

// neg: compute (-a)
fxp fxp_neg(fxp a);

fxp fxp_mul(fxp a, fxp b);
fxp fxp_add(fxp a, fxp b);

// fxp_sub: compute (a - b)
fxp fxp_sub(fxp a, fxp b);

#ifdef __cplusplus
}
#endif

#endif
