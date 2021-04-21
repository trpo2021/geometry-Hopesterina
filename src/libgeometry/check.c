#include "for_checking.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int name_verification(char* input_arr)
{
    char name_of_figure[6] = "Circle";
    int k = 0;
    for (int i = 0; i < 6; i++) {
        if (input_arr[i] != name_of_figure[i]) {
            k = k + 1;
            break;
        }
    }
    return k;
}

int checking_parameters_figure(char* input_arr)
{
    int j = 7; //индекс значения после "("
    int t = 0; //вспомогательная переменная

    if (input_arr[j] == ' ') {
        t = 1;
    }
    while (input_arr[j] != ' ') {
        if ((input_arr[j] != '-')
            && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0'))
                  || (input_arr[j] == '.')))
            && (input_arr[j] != ' ')) {
            t = 1;
            break;
        } else {
            j++;
        }
    }

    while ((input_arr[j] != ',') && (input_arr[j + 1] != ' ')) {
        if ((input_arr[j] != '-')
            && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0'))
                  || (input_arr[j] == '.')))
            && (input_arr[j] != ' ')) {
            t = 1;
            break;
        } else {
            j++;
        }
    }

    if (input_arr[j + 1] != ' ') {
        t = 1;
    }

    j++;

    while (input_arr[j] != ')') {
        if ((input_arr[j] != '-')
            && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0'))
                  || (input_arr[j] == '.')))
            && (input_arr[j] != ' ')) {
            t = 1;
            break;
        } else {
            j++;
        }
    }
    return t;
}

float area_f(float radius)
{
    return (M_PI * radius * radius);
}

float perimetr_f(float radius)
{
    return (2 * M_PI * radius);
}

void print_intersects(int ncircle, struct circle* data_circle)
{
    for (int i = 1; i < ncircle; i++) {
        for (int j = i + 1; j < ncircle + 1; j++) {
            int w = abs(data_circle[i].x - data_circle[j].x);
            int q = abs(data_circle[i].y - data_circle[j].y);
            if (sqrt(w * w + q * q) <= (data_circle[i].r + data_circle[j].r)) {
                printf("Circle %d intersects Circle %d \n", i, j);
            }
        }
    }
}
