#include "fixedpoint.h"

enum { N_FRACT_BITS = 26 };

fxp26 fxp26_from_int(int a) {
  const fxp26 ret = {.val = a << N_FRACT_BITS};
  return ret;
}

fxp26 fxp26_from_fl(float f) {
  const fxp26 ret = {.val = f * (1 << N_FRACT_BITS)};
  return ret;
}

fxp26 fxp26_from_dbl(double d) {
  const fxp26 ret = {.val = d * (1 << N_FRACT_BITS)};
  return ret;
}

float fxp26_to_fl(fxp26 a) {
  float x = a.val;
  return x / (1 << N_FRACT_BITS);
}

double fxp26_to_dbl(fxp26 a) {
  double x = a.val;
  return x / (1 << N_FRACT_BITS);
}

fxp26 fxp26_neg(fxp26 a) {
  a.val *= -1;
  return a;
}

fxp26 fxp26_mul(fxp26 a, fxp26 b) {
  const fxp26 ret = {.val = (a.val >> (N_FRACT_BITS / 2)) *
                            (b.val >> (N_FRACT_BITS / 2))};
  return ret;
}

fxp26 fxp26_add(fxp26 a, fxp26 b) {
  const fxp26 ret = {.val = (a.val + b.val)};
  return ret;
}

fxp26 fxp26_sub(fxp26 a, fxp26 b) { return fxp26_add(a, fxp26_neg(b)); }
