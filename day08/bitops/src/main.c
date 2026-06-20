#include <stdio.h>
#include "bit_test.h"

int main(void)
{
    test_macro();
    test_bit_field();
    test_endian_swap();
    test_struct_align();
    return 0;
}