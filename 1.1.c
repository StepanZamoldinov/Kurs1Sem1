#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Вычисляет a
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Число a
 */
double geta(double x, double y, double z);

/**
 * @brief Вычисляет b
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Число b
 */
double getb(double x, double y, double z);


/**
 * @brief Начало выполнения программы
 * @return Если всё успешно, 0
 */
int main(void) {
    const double x = 2.0;
    const double y = 0.7;
    const double z = -1.0;

    double a = geta(x, y, z);
    double b = getb(x, y, z);

    printf("x = %.1f\n", x);
    printf("y = %.1f\n", y);
    printf("z = %.1f\n", z);
    
    printf("a = %.16f\n", a);
    printf("b = %.16f\n", b);

    return 0;
}


double geta(double x, double y, double z) {
    return     cbrt(
                   x * y * z +
                   fabs(
                        z * sin(y)
                    )
               );
}

double getb(double x, double y, double z) {
    return     y *
               cos(
                   x * z *
                   sin(y)
               ) + 3;
}
