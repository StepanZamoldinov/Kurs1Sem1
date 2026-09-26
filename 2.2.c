#include <stdio.h>
#include <math.h>



 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0, если пользователь ввёл неверные данные, то 1
 */
int main(void) {
    const double a = 0.9;
    double x;

    if (!scanf("%lf", &x)) return 1;


    double result;
    if (x > 1.0) {
        result = a * log10(x) + sqrt(fabs(x));
    } else {
        result = 2*a * cos(x) + 3*x*x;
    }
    
    printf("%lf\n", result);
    return 0;
}
