#ifndef FXP_HPP
#define FXP_HPP

#include <cstdint>

template <int num_frac_bits> class fxp {
  static_assert(num_frac_bits % 2 == 0, "required to be even");

  fxp() = default;

public:
  fxp(int a) : val{a << num_frac_bits} {}
  fxp(float f) : val{static_cast<std::int32_t>(f * (1 << num_frac_bits))} {}
  fxp(double d) : val{static_cast<std::int32_t>(d * (1 << num_frac_bits))} {}

  float as_float() const { return float{val} / (1 << num_frac_bits); }

  double as_double() const { return double{val} / (1 << num_frac_bits); }

  std::int32_t get() const { return val; }

  fxp<num_frac_bits> operator-() const {
    auto x = *this;
    x.val = -x.val;
    return x;
  }

  fxp<num_frac_bits> operator*(fxp<num_frac_bits> rhs) {
    const auto a = val;
    const auto b = rhs.val;

    fxp<num_frac_bits> x;
    x.val = (a >> (num_frac_bits / 2)) * (b >> (num_frac_bits / 2));
    return x;
  }

  fxp operator+(fxp rhs) {
    fxp ret;
    ret.val = val + rhs.val;
    return ret;
  }

  fxp operator-(fxp rhs) { return *this + (-rhs); }

private:
  std::int32_t val;
};

#endif
