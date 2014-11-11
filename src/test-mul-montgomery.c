/**
 * RSA implementation and attack on Mbed
 * Big integers library - Tests for bgi_mul_bigint_by_int function
 * @author Cyrille Toulet, <cyrille.toulet@gmail.com>
 * @author Benjamin Burnouf, <benjamin76360@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include "bigint.h"
#include "test-mul-montgomery-dataset.c"

mbed_int main()
{
    mbed_int i = 0;
    mbed_bigint dest;

    while (i < TEST_MONT_MUL_COUNT)
    {
        bgi_init(dest);
        bgi_mul(dest, test_mul_bigint_by_int_dataset_x[i], test_mul_bigint_by_int_dataset_x[i],MAX_MBED_INT, m');

        if (bgi_cmp(dest, test_mul_bigint_by_int_dataset_y[i]) != 0)
        {
            printf("[FAIL] Test bgi_mul %d / %d", i + 1, TEST_MONT_MUL_COUNT);
            printf("\nNumber 1        : ");
            bgi_print(test_mul_bigint_by_int_dataset_x[i]);
            printf("\nExpected result : ");
            bgi_print(test_mul_bigint_by_int_dataset_y[i]);
            printf("\nReceived result : ");
            bgi_print(dest);
            putchar('\n');
            exit(EXIT_FAILURE);
        }

        printf("[PASS] Test bgi_mul %d / %d\n", i + 1, TEST_MUL_BIGINT_BY_INT_COUNT);
        i++;
    }

    exit(EXIT_SUCCESS);
}