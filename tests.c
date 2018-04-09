#include <stdio.h>
#include <stdbool.h>
#include "fixedpoint.h"

#define TERM_RED        "\033[0;31m"
#define TERM_GREEN      "\033[0;32m"
#define TERM_NOCOLOR    "\033[0m"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int failures = 0;
    {
        // Test case taken from http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/5-repr/fixed.html
        const char *tstDesc = "23.6875 is represented as 0 10111.10110000000000000000000000";

        const uint32_t expected = 0b01011110110000000000000000000000;
        uint32_t actual;

        bool passed = false;

        {
            fxp the = fxp_from_fl(23.6875f);
            actual = the.val;
            passed = (actual == expected);
        }

        if (passed)
            printf(TERM_GREEN "%s", tstDesc);
        else {
            printf(TERM_RED "%s", tstDesc);
            printf("\n\tExpected: 0x%x\tActual: 0x%x", expected, actual);
            failures++;
        }
        puts(TERM_NOCOLOR "");
    }

    {
        bool passed = false;
        const char *tstDesc = "2.25 * 2.25 = 5.0625";
        int32_t expected = fxp_from_dbl(5.0625).val;

        {
            fxp a = fxp_from_fl(2.25f);
            fxp b = fxp_from_fl(2.25f);

            fxp c = fxp_mul(a, b);

            passed = c.val == expected;
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
        int32_t expected = fxp_from_int(1).val;

        {
            fxp a = fxp_from_fl(.5);
            fxp b = fxp_from_fl(.5);

            fxp c = fxp_add(a, b);

            passed = c.val == expected;
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
        int32_t expected = fxp_from_fl(.25).val;
        {
            fxp a = fxp_from_fl(.75);
            fxp b = fxp_from_fl(-.5);

            fxp c = fxp_add(a, b);

            passed = c.val == expected;
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
        int32_t expected = fxp_from_fl(.25).val;
        {
            fxp a = fxp_from_fl(.75);
            fxp b = fxp_from_fl(.5);

            fxp c = fxp_sub(a, b);

            passed = c.val == expected;
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
