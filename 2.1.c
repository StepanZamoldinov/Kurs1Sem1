#include <stdio.h>
#include <stdlib.h>


double get_dim(void);


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
