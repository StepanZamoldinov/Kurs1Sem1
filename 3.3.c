#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef unsigned long long ull;

 /**
 * @brief Получить число типа long double от пользователя
 * @return Число от пользователя
 */
ld get_long_double(void);

 /**
 * @brief Вычислить сумму функционального ряда для функции e^(2x) с заданной точностью
 * @param x Вычисляемое число
 * @param epsilon Точность вычисления
 * @return Результат вычисления суммы
 */
ld solve_for_x(const ld x, const ld epsilon);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0
 */
int main(void) {
    printf("Enter step: ");
    const ld step = get_long_double();
    printf("Enter interval start: ");
    const ld interval_start = get_long_double();
    printf("Enter interval end: ");
    const ld interval_end = get_long_double();
    printf("Enter precision: ");
    const ld epsilon = get_long_double();

    printf("      x      |    e^(2x)    |     Sum\n");
    for (ld x = interval_start; x <= interval_end + step / 2.0L; x += step) {
        ld result = powl(M_E, 2.0L * x);
        ld sum_result = solve_for_x(x, epsilon);
        printf("%.10Lf | %.10Lf | %.10Lf\n", x, result, sum_result);
    }
    return 0;
}

ld solve_for_x(const ld x, const ld epsilon) {
    ld result = 1.0;
    ld last = 1.0;
    ull n = 1ULL;
    while (1u) {
        last = last * (2*x / (ld)n);
        result += last;
        if (last < epsilon) break;
        n++;
    }
    return result;
    
}


ld get_long_double(void) {
    ld ret = 0.0L;
    if (scanf("%Lf", &ret) != 1) exit(1);
    return ret;
}
