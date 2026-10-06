#include <stdio.h>
#include <stdlib.h>


 /**
 * @brief Получить число типа int от пользователя
 * @return Число от пользователя
 */
int get_int();


 /**
 * @brief Начало выполнения программы
 * @return 0 если всё хорошо, 1 если введено неправильное время суток
 */
int main(void) {
    printf("Current time(hours): ");
    int hours = get_int();
    if (hours < 0 || hours > 23) return 1;
    printf("Current time(minutes): ");
    int minutes = get_int();
    if (minutes < 0 || minutes > 59) return 1;

    if      (hours >= 6  && hours < 10) printf("Good morning!\n");
    else if (hours >= 10 && hours < 18) printf("Good afternoon!\n");
    else if (hours >= 18 && hours < 23) printf("Good evening!\n");
    else                                printf("Good night\n");
    
    
    return 0;
}

int get_int() {
    int ret = 0;
    if (scanf("%d", &ret) != 1) exit(1);
    return ret;
}
