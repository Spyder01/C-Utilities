#include "vector.h"
#include <stdio.h>

int main() {
    // Define a vector of integers
    DEFINE_VECTOR_TYPE(int, IntVector);

    // Initialize an integer vector
    IntVector *intVector = IntVectorInit(4);

    // Add elements to the integer vector
    IntVectorAdd(intVector, 10);
    IntVectorAdd(intVector, 20);
    IntVectorAdd(intVector, 30);

    // Access and print elements from the integer vector
    printf("IntVector[0]: %d\n", IntVectorGet(intVector, 0));
    printf("IntVector[1]: %d\n", IntVectorGet(intVector, 1));
    printf("IntVector[2]: %d\n", IntVectorGet(intVector, 2));

    // Free the integer vector
    IntVectorFree(intVector);

    // Define a vector of floats
    DEFINE_VECTOR_TYPE(float, FloatVector);

    // Initialize a float vector
    FloatVector *floatVector = FloatVectorInit(4);

    // Add elements to the float vector
    FloatVectorAdd(floatVector, 1.5f);
    FloatVectorAdd(floatVector, 2.5f);
    FloatVectorAdd(floatVector, 3.5f);

    // Access and print elements from the float vector
    printf("FloatVector[0]: %.2f\n", FloatVectorGet(floatVector, 0));
    printf("FloatVector[1]: %.2f\n", FloatVectorGet(floatVector, 1));
    printf("FloatVector[2]: %.2f\n", FloatVectorGet(floatVector, 2));

    // Free the float vector
    FloatVectorFree(floatVector);

    // Define a vector of doubles
    DEFINE_VECTOR_TYPE(double, DoubleVector);

    // Initialize a double vector
    DoubleVector *doubleVector = DoubleVectorInit(4);

    // Add elements to the double vector
    DoubleVectorAdd(doubleVector, 1.55);
    DoubleVectorAdd(doubleVector, 2.55);
    DoubleVectorAdd(doubleVector, 3.55);

    // Access and print elements from the double vector
    printf("DoubleVector[0]: %.2lf\n", DoubleVectorGet(doubleVector, 0));
    printf("DoubleVector[1]: %.2lf\n", DoubleVectorGet(doubleVector, 1));
    printf("DoubleVector[2]: %.2lf\n", DoubleVectorGet(doubleVector, 2));

    // Free the double vector
    DoubleVectorFree(doubleVector);

    return 0;
}

