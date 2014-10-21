/**
 * RSA implementation and attack on Mbed
 * Big integers library - Tests for bgi_add function
 * @author Cyrille Toulet, <cyrille.toulet@gmail.com>
 * @author Benjamin Burnouf, <benjamin76360@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include "bigint.h"
#include "test-add-dataset.c"

mbed_int main()
{
    mbed_int i;

    for (i = 0; i < TEST_ADD_COUNT - 1; i++)
    {
        mbed_bigint dest;

        bgi_init(&dest);
        bgi_add(&dest, test_add_dataset[i][0], test_add_dataset[i][1]);

        if (bgi_cmp(dest, test_add_dataset[i][2]) != 0)
        {
            printf("[FAIL] Test %d / %d", i + 1, TEST_ADD_COUNT);
            printf("\nNumber 1        : ");
            bgi_print(test_add_dataset[i][0]);
            printf("\nNumber 2        : ");
            bgi_print(test_add_dataset[i][1]);
            printf("\nExpected result : ");
            bgi_print(test_add_dataset[i][2]);
            printf("\nReceived result : ");
            bgi_print(dest);
            putchar('\n');
            exit(EXIT_FAILURE);
        }
    }

    printf("[ OK ]\n");

    exit(EXIT_SUCCESS);
}
