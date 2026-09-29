#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

typedef long double ld;
typedef unsigned long long ull;

 /**
 * @brief Вычислить сумму функционального ряда для функции e^(2x) с заданной точностью
 * @param x Вычисляемое число
 * @param epsilon Точность вычисления
 * @return Результат вычисления суммы
 */
ld solve_for_x(ld x, ld epsilon);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0
 */
int main(void) {
    const ld step = 0.1L;
    const ld interval_start = 0.1L;
    const ld interval_end = 1.0L;
    const ld epsilon = 0.00000625L;

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
