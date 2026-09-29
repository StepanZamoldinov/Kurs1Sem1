#include <stdio.h>


 /**
 * @brief перевести байты в мегабайты(примерно)
 * @param bytes Кол-во байтов
 * @return примерное кол-во мегабайтов
 */
double get_mb(const long long int bytes);

 /**
 * @brief перевести байты в гигабайты(примерно)
 * @param bytes Кол-во байтов
 * @return примерное кол-во гигабайтов
 */
double get_gb(const long long int bytes);



 /**
 * @brief Начало выполнения программы
 * @return если всё прошло успешно, то 0
 */
int main(void) {
    long long int bytes = 0;
    scanf("%lld", &bytes);
    
    printf("MB = %.4lf\nGB = %.4lf\n", get_mb(bytes), get_gb(bytes));

    return 0;
}


double get_mb(const long long int bytes) {
    return (double)bytes / (1024.0*1024.0);
}

double get_gb(const long long int bytes) {
    return (double)bytes / (1024.0*1024.0*1024.0);
}
