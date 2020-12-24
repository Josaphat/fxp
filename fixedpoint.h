#ifndef FIXEDPOINT_FIXEDPOINT_H
#define FIXEDPOINT_FIXEDPOINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  int32_t val;
} fxp26;

fxp26 fxp26_from_int(int a);
fxp26 fxp26_from_fl(float f);
fxp26 fxp26_from_dbl(double d);

float fxp26_to_fl(fxp26 a);
double fxp26_to_dbl(fxp26 a);

// neg: compute (-a)
fxp26 fxp26_neg(fxp26 a);

fxp26 fxp26_mul(fxp26 a, fxp26 b);
fxp26 fxp26_add(fxp26 a, fxp26 b);

// fxp_26_sub: compute (a - b)
fxp26 fxp26_sub(fxp26 a, fxp26 b);

#ifdef __cplusplus
}
#endif

#endif
