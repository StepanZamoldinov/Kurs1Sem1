#include <stdio.h>
#include <string.h>

 /**
 * @brief Начало выполнения программы
 * @return 0 если всё хорошо, 1 если введено неправильное время суток
 */
int main(void) {
    char daytime[11];
    printf("Enter the current time of the day: ");
    if (fgets(daytime, sizeof(daytime), stdin) == NULL) return 1;

    daytime[strcspn(daytime, "\n")] = '\0';

    if      (strcmp(daytime, "Morning")   == 0 || strcmp(daytime, "morning")   == 0) printf("Good morning!\n");
    else if (strcmp(daytime, "Afternoon") == 0 || strcmp(daytime, "afternoon") == 0) printf("Good afternoon!\n");
    else if (strcmp(daytime, "Evening")   == 0 || strcmp(daytime, "evening")   == 0) printf("Good evening!\n");
    else if (strcmp(daytime, "Night")     == 0 || strcmp(daytime, "night")     == 0) printf("Good night!\n");
    else return 1;
        
    return 0;
}
