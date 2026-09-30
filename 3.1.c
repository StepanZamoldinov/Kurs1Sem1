#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /**
 * @brief Получить число типа double от пользователя
 * @return Число от пользователя
 */
double get_double();

 /**
 * @brief Начало выполнения программы
 * @return 0 если всё успешно, 1 если был неправильный ввод от пользователя
 */
int main(void) {
    printf("Interval start: ");
    double xstart = get_double();
    printf("Interval end: ");
    double xend = get_double();
    
    printf("Step: ");
    double dx = get_double();

    for (double x = xstart; x < xend + dx / 2.0; x += dx) {
        if (!(x > 0.0)) {
            printf("Impossible x: %.10lf\n", x);
            continue;
        }
        double y = 0.1*x*x - x*log(x);
        printf("%.10lf | %.10lf\n", x, y);
    }
    
    return 0;
}


double get_double() {
    double ret = 0.0;
    if (scanf("%lf", &ret) != 1) exit(1);
    return ret;
}
