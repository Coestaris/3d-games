#include <stdio.h>
#include "../common/fixed.h"

#define do_test(str, macro, a, b) {                                  \
     fixed_t res = macro(a, b);                                      \
     printf(str"(a = %i, b = %i) = %i.%i\n", a, b, I(res), D(res));  \
   }

int main()
{
   fixed_t a = F(231, 53);

   printf("a = %i\n", a);
   printf("i = %i\n", I(a));
   printf("d = %i\n", D(a));

   do_test("FI_ADD", FF_ADD, F(10, 2), F(51, 3431));
   do_test("FI_ADD", FI_ADD, F(10, 2), 125);
   do_test("FI_ADD", IF_ADD, 525, F(51, 4224));
   do_test("FI_ADD", II_ADD, 123, 512);

   do_test("FI_SUB", FF_SUB, F(10, 2), F(51, 3431));
   do_test("FI_SUB", FI_SUB, F(10, 2), 125);
   do_test("FI_SUB", IF_SUB, 525, F(51, 4224));
   do_test("FI_SUB", II_SUB, 123, 512);

   do_test("FI_MUL", FF_MUL, F(10, 2), F(51, 3431));
   do_test("FI_MUL", FI_MUL, F(10, 2), 125);
   do_test("FI_MUL", IF_MUL, 525, F(51, 4224));
   do_test("FI_MUL", II_MUL, 123, 512);

   do_test("FI_DIV", FF_DIV, F(10, 2), F(51, 3431));
   do_test("FI_DIV", FI_DIV, F(10, 2), 125);
   do_test("FI_DIV", IF_DIV, 525, F(51, 4224));
   do_test("FI_DIV", II_DIV, 123, 512);

   return 0;
}
