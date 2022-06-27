#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    float input = get_float("Change owed: ");
    if (input < 0){
        input = get_float("Change owed: ");
    }
    int count = 0;
    int cents = round(input * 100);
    while (cents != 0){
        if (cents - 25 >= 0){
            count++;
            cents -= 25;
        }
        else if (cents - 10 >= 0){
            count++;
            cents -= 10;
        }
        else if (cents - 5 >= 0){
            count++;
            cents -= 5;
        }
        else if (cents - 1 >= 0){
            count++;
            cents -= 1;
        }
    }
    printf("%i\n", count);
}