#include <stdio.h>
#include <stdlib.h>

 /**
 * @brief Получить одну сторону параллелепипеда от пользователя
 * @return Одна из сторон параллелепипеда
 */
double get_dim(void);

 /**
 * @brief Вычислить объём параллелепипеда
 * @param length Длина
 * @param width Ширина
 * @param height Высота
 * @return Объём
 */
double get_volume(const double length, const double width, const double height);


 /**
 * @brief Вычислить площадь поверхности параллелепипеда
 * @param length Длина
 * @param width Ширина
 * @param height Высота
 * @return Площадь поверхности
 */
double get_surface_area(const double length, const double width, const double height);

 /**
 * @brief Начало выполнения программы
 * @return Если всё прошло успешно, то 0, если пользователь ввёл неправильное значение, то 1
 */
int main(void) {
    double length = get_dim();
    double width = get_dim();
    double height = get_dim();

    double volume = get_volume();
    double surface_area = get_surface_area();
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


double get_volume(const double length, const double width, const double height) {
    return length*width*height;
}

double get_surface_area(const double length, const double width, const double height) {
    return 2*(length*width) + 2*(length*height) + 2*(height*width);
}
