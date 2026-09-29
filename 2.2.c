#include <stdio.h>
#include <math.h>




double calculate_result(const double x, const double a);


 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0, если пользователь ввёл неверные данные, то 1
 */
int main(void) {
    const double a = 0.9;
    double x = 0.0;

    if (scanf("%lf", &x) != 1) return 1;

    double result = calculate_result(x, a);
    
    printf("%lf\n", result);
    return 0;
}


double calculate_result(const double x, const double a) {
    if (x > 1.0) {
        return a * log10(x) + sqrt(fabs(x));
    } else {
        return 2*a * cos(x) + 3*x*x;
    }
}
