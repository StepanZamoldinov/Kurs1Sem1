#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ull;
typedef long double ld;

 /**
 * @brief Получить от пользователя число типа unsigned long long
 * @return Число от пользователя
 */
ull get_ull(void);

 /**
 * @brief Получить от пользователя число типа long double
 * @return Число от пользователя
 */
ld get_ld(void);

 /**
 * @brief Вычисляет следующий элемент суммы рекуррентным способом
 * @param last Предыдущий элемент суммы
 * @param k Номер текущего элемента суммы
 * @return Следующий элемент суммы
 */
ld calculate_next(ld last, ld k);

 /**
 * @brief Вычислить сумму первых n членов последовательности (k=1,2,3,...,n) рекуррентным способом
 * @param n Количество элементов суммы
 * @return Вычисленное значение
 */
ld calculate_sum_n(ld n);

 /**
 * @brief Вычислить сумму всех членов последовательности, по модулю не меньших заданного epsilon рекуррентным способом
 * @param epsilon точность вычисления, т.е. минимальный элемент последовательности который будет суммироваться
 * @return Вычисленное значение
 */
ld calculate_sum_epsilon(ld epsilon);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло учпешно, то 0, если пользователь ввёл неправильное число, то 1
 */
int main(void) {
    printf("Enter count: ");
    ull n = get_ull();
    if (!n) return 1;
    printf("Enter precision: ");
    ld epsilon = get_ld();
    if (epsilon <= 0.0L) return 1;

    printf("=================\n");
    ld sum_n = calculate_sum_n(n);
    ld sum_epsilon = calculate_sum_epsilon(epsilon);

    printf("Sum of %llu elements:\n\t%.32Lf\nSum of elements with precision of %.32Lf:\n\t%.32Lf\n", n, sum_n, epsilon, sum_epsilon);
    printf("=================\n");
    printf("ADDITIONAL TASK:\n");
    for (unsigned short i = 1000u; i < 9999u; i++) {
        if (
            (i / 1000u + i % 10u == i % 1000u / 100u + i % 100u / 10u)
            &&
            (i % 6 == 0 && i % 27 == 0)
        ) printf("\t%u\n", i);
    }

    return 0;
}

ull get_ull(void) {
    ull ret = 0ULL;
    if (scanf("%llu", &ret) != 1) exit(1);
    return ret;
}

ld get_ld(void) {
    ld ret = 0.0L;
    if (scanf("%Lf", &ret) != 1) exit(1);
    return ret;
}

ld calculate_next(ld last, ld k) {
    return last * (-1) / ((2*k - 1) * (2*k - 2));
}

ld calculate_sum_n(ld n) {
    ld last = 1.0L;
    ld sum = last;
    ull k = 1;
    while (k++ < n) {
        last = calculate_next(last, k);
        sum += last;
    }
    return sum;
}

ld calculate_sum_epsilon(ld epsilon) {
    ld last = 1.0L;
    ld sum = last;
    ull k = 1;
    while (1) {
        k++;
        last = calculate_next(last, k);
        if (fabsl(last) < epsilon) break;
        sum += last;
    }
    return sum;
}
