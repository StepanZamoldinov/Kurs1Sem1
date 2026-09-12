#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define X 2.0
#define Y 0.7
#define Z -1.0


int main(void) {
    double a = cbrt(
                    X * Y * Z +
                    fabs(
                         Z * sin(Y)
                     )
                );

    double b = Y *
               cos(
                   X * Z *
                   sin(Y)
               ) + 3;

    printf("x = %.1f\n", X);
    printf("y = %.1f\n", Y);
    printf("z = %.1f\n", Z);
    
    printf("a = %.16f\n", a);
    printf("b = %.16f\n", b);

    return 0;
}

