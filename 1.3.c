#include <stdio.h>

 /**
 * @brief Получить от пользователя сопротивление одного из резисторов
 * @return Сопротивление одного резистора
 */
double get_resistor(void);


 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0
 */
int main(void) {
    double total = 0;
    for (int i = 0; i < 3; i++) total += get_resistor();

    printf("Total resistance = %.4lf\n", total);
    return 0;
}

double get_resistor() {
    double user_value = 0;
    scanf("%lf", &user_value);
    return user_value;
}
