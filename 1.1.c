#include <math.h>
#include <stdio.h>


#define X 1.426
#define Y -1.22
#define Z 3.5

#define PI 3.141592653589793


int main(void) {
    double a =
        (2.0 * cos(X - PI/6))
                 /
        (0.5 + pow(sin(Y), 2));

    double b = 1 +
        pow(Z, 2)
           /
        (3 + pow(Z, 2) / 5);
    

    printf("x = %.3f\n", X);
    printf("y = %.2f\n", Y);
    printf("z = %.1f\n", Z);
    
    printf("a = %.16f\n", a);
    printf("b = %.16f\n", b);

    return 0;
}

