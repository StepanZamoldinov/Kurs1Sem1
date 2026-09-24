#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define X 2.0
#define Y 0.7
#define Z -1.0


/**
 * @brief Вычисляет a
 * @return Число a
 */
double geta(void);

/**
 * @brief Вычисляет b
 * @return Число b
 */
double getb(void);


/**
 * @brief Начало выполнения программы
 * @return Если всё успешно, 0
 */
int main(void) {
    double a = geta();
    double b = getb();

    printf("x = %.1f\n", X);
    printf("y = %.1f\n", Y);
    printf("z = %.1f\n", Z);
    
    printf("a = %.16f\n", a);
    printf("b = %.16f\n", b);

    return 0;
}


double geta(void) {
    return     cbrt(
                   X * Y * Z +
                   fabs(
                        Z * sin(Y)
                    )
               );
}

double getb(void) {
    return     Y *
               cos(
                   X * Z *
                   sin(Y)
               ) + 3;
}
