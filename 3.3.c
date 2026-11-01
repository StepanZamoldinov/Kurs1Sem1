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
 * @param precise точное значение суммы
 * @return Результат вычисления суммы
 */
double solve_for_x(const double x, const double epsilon, const double precise);

 /**
 * @brief Вычислить e^(2x)
 * @param x Параметр
 * @return Результат вычисления
 */
double solve_for_x_normal(const double x);

 /**
 * @brief Завершить выполнение программы и вывести ошибку
 * @param message Сообщение об ошибке
 */
void exit_with_message(const char *message);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0, если ввод неправильный, то 1
 */
int main(void) {
    printf("Enter step: ");
    const double step = get_double();
    if (step <= 0.0) exit_with_message("Step should be >0");
    
    printf("Enter interval start: ");
    const double interval_start = get_double();
    printf("Enter interval end: ");
    const double interval_end = get_double();
    if (interval_end < interval_start) exit_with_message("Interval end should be greater or equal interval start");
    
    printf("Enter precision: ");
    const double epsilon = get_double();
    if (epsilon <= 0.0) exit_with_message("Precision should be >0");

    printf("      x      |    e^(2x)    |     Sum\n");
    for (double x = interval_start; x <= interval_end + step / 2.0; x += step) {
        double result = solve_for_x_normal(x);
        double sum_result = solve_for_x(x, epsilon, result);
        printf("%.10lf | %.10lf | %.10lf\n", x, result, sum_result);
    }
    return 0;
}

double solve_for_x(const double x, const double epsilon, const double precise) {
    double result = 0.0;
    double last = 1.0;
    int n = 1;
    while (fabs(precise - result) >= epsilon) {
        result += last;
        last = last * (2*x / (double)n);
        n++;
    }

    return result;
}

double solve_for_x_normal(const double x) {
    return exp(2.0 * x);
}

double get_double(void) {
    double ret = 0.0;
    if (scanf("%lf", &ret) != 1) exit(1);
    return ret;
}

void exit_with_message(const char *message) {
    if (message != NULL) {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}
