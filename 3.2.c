#include <stdio.h>
#include <stdlib.h>
#include <math.h>


 /**
 * @brief Получить от пользователя число типа int
 * @return Число от пользователя
 */
int get_int(void);

 /**
 * @brief Получить от пользователя число типа double
 * @return Число от пользователя
 */
double get_double(void);

 /**
 * @brief Вычисляет следующий элемент суммы рекуррентным способом
 * @param last Предыдущий элемент суммы
 * @param k Номер текущего элемента суммы
 * @return Следующий элемент суммы
 */
double calculate_next(double last, double k);

 /**
 * @brief Вычислить сумму первых n членов последовательности (k=1,2,3,...,n) рекуррентным способом
 * @param n Количество элементов суммы
 * @return Вычисленное значение
 */
double calculate_sum_n(double n);

 /**
 * @brief Вычислить сумму всех членов последовательности, по модулю не меньших заданного epsilon рекуррентным способом
 * @param epsilon точность вычисления, т.е. минимальный по модулю элемент последовательности который будет суммироваться
 * @return Вычисленное значение
 */
double calculate_sum_epsilon(double epsilon);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло учпешно, то 0, если пользователь ввёл неправильное число, то 1
 */
int main(void) {
    printf("Enter count: ");
    int n = get_int();
    if (n <= 0) return 1;
    printf("Enter precision: ");
    double epsilon = get_double();
    if (epsilon <= 0.0) return 1;

    printf("=================\n");
    double sum_n = calculate_sum_n(n);
    double sum_epsilon = calculate_sum_epsilon(epsilon);

    printf("Sum of %d elements:\n\t%.32lf\nSum of elements with precision of %.32lf:\n\t%.32lf\n", n, sum_n, epsilon, sum_epsilon);
    printf("=================\n");
    printf("ADDITIONAL TASK(var 9):\n");
    for (unsigned short i = 1000u; i < 9999u; i++) {
        if (
            (i / 1000u + i % 10u == i % 1000u / 100u + i % 100u / 10u)
            &&
            (i % 6 == 0 && i % 27 == 0)
        ) printf("\t%u\n", i);
    }

    return 0;
}

int get_int(void) {
    int ret = 0;
    if (scanf("%d", &ret) != 1) exit(1);
    return ret;
}

double get_double(void) {
    double ret = 0.0;
    if (scanf("%lf", &ret) != 1) exit(1);
    return ret;
}

double calculate_next(double last, double k) {
    return last * (-1) / ((2*k - 1) * (2*k - 2));
}

double calculate_sum_n(double n) {
    double last = 1.0L;
    double sum = last;
    int k = 1;
    while (k++ < n) {
        last = calculate_next(last, k);
        sum += last;
    }
    return sum;
}

double calculate_sum_epsilon(double epsilon) {
    double last = 1.0;
    double sum = last;
    int k = 1;
    while (fabs(last) >= epsilon) {
        k++;
        last = calculate_next(last, k);
        if (fabs(last) >= epsilon) {
            sum += last;
        }
    }
    return sum;
}
