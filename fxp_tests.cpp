#include "fxp.hpp"
#include <cstdint>
#include <cstdio>

#define TERM_RED "\033[0;31m"
#define TERM_GREEN "\033[0;32m"
#define TERM_NOCOLOR "\033[0m"

int main(int /*argc*/, char * /*argv*/ []) {
  int failures = 0;

  {
    // Test case taken from
    // http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/5-repr/fixed.html
    const char *tstDesc =
        "C++: 23.6875 is represented as 0 10111.10110000000000000000000000";

    const std::uint32_t expected = 0b01011110110000000000000000000000;
    std::uint32_t actual;

    bool passed = false;

    {
      fxp<26> the{23.6875f};
      actual = the.get();
      passed = (actual == expected);
    }

    if (passed)
      std::printf(TERM_GREEN "%s", tstDesc);
    else {
      std::printf(TERM_RED "%s", tstDesc);
      std::printf("\n\tExpected: 0x%x\tActual: 0x%x", expected, actual);
      failures++;
    }
    std::puts(TERM_NOCOLOR "");
  }

  {
    bool passed = false;
    const char *tstDesc = "C++: 2.25 * 2.25 = 5.0625";
    int32_t expected = fxp<26>(5.0625).get();

    {
      fxp<26> a{2.25f};
      fxp<26> b{2.25f};

      auto c = a * b;

      passed = c.get() == expected;
    }

    if (passed)
      printf(TERM_GREEN "%s", tstDesc);
    else {
      printf(TERM_RED "%s", tstDesc);
      failures++;
    }
    puts(TERM_NOCOLOR "");
  }

  {
    bool passed = false;
    const char *tstDesc = ".5 + .5 = 1.0";
    int32_t expected = fxp<26>(1.0).get();

    {
      fxp<26> a{.5};
      fxp<26> b{.5};

      auto c = a + b;

      passed = c.get() == expected;
    }

    if (passed)
      printf(TERM_GREEN "%s", tstDesc);
    else {
      printf(TERM_RED "%s", tstDesc);
      failures++;
    }
    puts(TERM_NOCOLOR "");
  }

  {
    const char *tstDesc = ".75 + (-0.5) = .25";
    bool passed = false;
    int32_t expected = fxp<26>(.25).get();
    {
      fxp<26> a{.75};
      fxp<26> b{-.5};

      auto c = a + b;

      passed = c.get() == expected;
    }
    if (passed)
      printf(TERM_GREEN "%s", tstDesc);
    else {
      printf(TERM_RED "%s", tstDesc);
      failures++;
    }
    puts(TERM_NOCOLOR "");
  }

  {
    const char *tstDesc = ".75 - 0.5 = .25";
    bool passed = false;
    int32_t expected = fxp<26>{.25f}.get();
    {
      fxp<26> a{.75};
      fxp<26> b{.5};

      auto c = a - b;

      passed = c.get() == expected;
    }
    if (passed)
      printf(TERM_GREEN "%s", tstDesc);
    else {
      printf(TERM_RED "%s", tstDesc);
      failures++;
    }
    puts(TERM_NOCOLOR "");
  }

  return failures;
}
