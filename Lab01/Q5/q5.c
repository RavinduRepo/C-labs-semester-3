#include<stdio.h>
#define pi 3.14159265

int main(){

    double radious, surface_Area, volume;

    printf("Enter the radious of the sphere: ");
    scanf("%lf", &radious);


    surface_Area = 4.0 * pi * radious * radious;
    volume = 4.0 / 3.0 * pi *radious * radious * radious;

    printf("Surface area of the sphere is: %lf\n", surface_Area);
    printf("Volume of the sphere is: %lf\n", volume);


    return 0;
}