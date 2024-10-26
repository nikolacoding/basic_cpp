#include <stdio.h>
#include <stdlib.h>
#include "IntArray.h"

int main()
{
    IntArray intArray;

    IntArray__initalize(&intArray);

    for (int i = 0; i < 4; i++)
    {
        IntArray__append(&intArray, i);
    }

    for (int i = 0; i < intArray.length; i++)
    {
        printf("%d\n", intArray.array[i]);
    }

    IntArray__free(&intArray);
}