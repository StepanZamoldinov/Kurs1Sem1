#include <stdio.h>
#include <stdlib.h>

 /**
 * @brief Получить одну сторону параллелепипеда от пользователя
 * @return Одна из сторон параллелепипеда
 */
double get_dim(void);



 /**
 * @brief Начало выполнения программы
 * @brief Если всё прошло успешно, то 0, если пользователь ввёл неправильное значение, то 1
 */
int main(void) {
    double length = get_dim();
    double width = get_dim();
    double height = get_dim();

    double volume = length*width*height;
    double surface_area = 2*(length*width) + 2*(length*height) + 2*(height*width);
    printf("Volume: %.4lf\nSurface area: %.4lf\n", volume, surface_area);
    return 0;
}

double get_dim(void) {
    double dim = 0.0;

    if (!scanf("%lf", &dim)) {
        exit(1);
    }

    return dim;
}
