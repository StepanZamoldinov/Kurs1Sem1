#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 /**
 * @brief Получить число типа double от пользователя
 * @return Число от пользователя
 */
double get_double(void);

 /**
 * @brief Вычислить сумму функционального ряда для функции e^(2x) с заданной точностью
 * @param x Вычисляемое число
 * @param epsilon Точность вычисления
 * @return Результат вычисления суммы
 */
double solve_for_x(const double x, const double epsilon);

 /**
 * @brief Вычислить e^(2x)
 * @param x Параметр
 * @return Результат вычисления
 */
double solve_for_x_normal(const double x);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0, если ввод неправильный, то 1
 */
int main(void) {
    printf("Enter step: ");
    const double step = get_double();
    if (step < 0.0L) return 1;
    
    printf("Enter interval start: ");
    const double interval_start = get_double();
    printf("Enter interval end: ");
    const double interval_end = get_double();
    if (interval_end < interval_start) return 1;
    
    printf("Enter precision: ");
    const double epsilon = get_double();
    if (epsilon <= 0.0L) return 1;

    printf("      x      |    e^(2x)    |     Sum\n");
    for (double x = interval_start; x <= interval_end + step / 2.0L; x += step) {
        double result = solve_for_x_normal(x);
        double sum_result = solve_for_x(x, epsilon);
        printf("%.10lf | %.10lf | %.10lf\n", x, result, sum_result);
    }
    return 0;
}

double solve_for_x(const double x, const double epsilon) {
    double result = 1.0;
    double last = 1.0;
    int n = 1;
    do {
        last = last * (2*x / (double)n);
        result += last;
        n++;
    } while (last >= epsilon);

    return result;
}

double solve_for_x_normal(const double x) {
    return exp(2.0 * x);
}

double get_double(void) {
    double ret = 0.0L;
    if (scanf("%lf", &ret) != 1) exit(1);
    return ret;
}
