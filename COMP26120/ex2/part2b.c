//C program to convert Fahrenheit to Celsius
#include <stdio.h>
 
int main(void)
{
    float celsius, fahrenheit, temp;
    char option[2];
    
    scanf("%s %f", option, temp);

    if (option[1] == 'c')
    {
       celsius = temp;
       fahrenheit = 1.8 * celsius + 32;
       printf("\n %.2f °C = %.2f °F \n", celsius, fahrenheit);
    }
    else if(option[1] == 'f') 
    {
       fahrenheit = temp;
       celsius = (fahrenheit - 32) * 5 / 9;
       printf("\n %.2f °F = %.2f °C \n", fahrenheit, celsius);
    }
}

