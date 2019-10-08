#include<stdio.h>
#include<stdlib.h>
int main(){
    int min = 0;
    int max = 0;
    printf("Lower limit: ");
    scanf("%d", &min);
    printf("Upper Limit: ");
    scanf("%d", &max);
    printf("Celcius\t\tFahrenheit\n");
    printf("==========================\n");
    float newMax = min;
    while (min <= max)
    {
        newMax *= (9/5) + 32;
        printf("%d\t\t%.1f \n", min, newMax);
        min+=5;
    }
    
}