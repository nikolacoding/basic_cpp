#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "IntArray.h"

int main()
{
    IntArray intArray;

    for (int i = 0; i < 20; i++)
    {
        intArray.append(i);
    }

    for (int i = 0; i < intArray.getLength(); i++)
    {
        printf("%d\n", intArray.at(i));
    }

    intArray.dispose();
}