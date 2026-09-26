#include <stdio.h>

 /**
 * @brief Начало выполнения программы
 * @return если всё прошло успешно, то 0
 */
int main(void) {
    long long int bytes;
    scanf("%lld", &bytes);
    
    printf("MB = %.4lf\nGB = %.4lf\n", (double)bytes / (1024.0*1024.0), (double)bytes / (1024.0*1024.0*1024.0));

    return 0;
}
