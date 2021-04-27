#include "libgeometry/for_checking.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 30 // максимальная длина строки

int main()
{
    struct circle data_circle[50]; // массив структур для записи всех параметров
                                   // кругов
    float r = 0;                   // радиус
    float area = 0, perimetr = 0;
    int ncircle = 0; // количество кругов
    FILE* fptr = NULL;

    fptr = fopen("bin/input.txt", "r");
    if (!fptr) {
        printf("Can`t open the file\n");
    } else {
        while (!feof(fptr)) //проход до конца файла
        {
            char r_arr[10] = {0};
            char x_arr[10] = {0}; // зануляем параметры фигуры
            char y_arr[10] = {0};
            char input_arr[N]
                    = {0}; //каждую итерацию зануляем массив, для новой строчки
            fgets(input_arr, 30, fptr);
            printf("\n");

            int counter_1 = name_verification(input_arr);
            int counter_2 = checking_parameters_figure(input_arr);

            if (counter_1 > 0) {
                for (int i = 0; i < N; i++) {
                    printf("%c", input_arr[i]);
                }
                printf("incorrect name of figure\n");
                printf("please correct\n"); // ошибка об имени

            } else {
                if (counter_2 > 0) {
                    for (int i = 0; i < N; i++) {
                        printf("%c", input_arr[i]);
                    }
                    printf("invalid values\n");
                    printf("please correct\n"); // ошибка о параметрах фигуры
                } else {
                    for (int i = 0; i < N; i++) {
                        if ((input_arr[i] == ',')
                            && (input_arr[i + 1] == ' ')) { // поиск радиуса
                            for (int k = i; input_arr[k + 1] != ')'; k++) {
                                r_arr[k - i] = input_arr[k + 1];
                            }
                        }
                        if (input_arr[i] == '(') { // поиск x
                            for (int k = i; input_arr[k + 1] != ' '; k++) {
                                x_arr[k - i] = input_arr[k + 1];
                            }
                        }
                        if (input_arr[i] == ' ') { // поиск y
                            for (int k = i - 1; input_arr[k] != ','; k++) {
                                y_arr[k - i] = input_arr[k];
                            }
                        }
                    }
                    ++ncircle;
                    r = atof(r_arr);
                    area = area_f(r);
                    perimetr = perimetr_f(r);

                    printf("%d. ", ncircle);
                    for (int i = 0; i < N; i++) {
                        printf("%c", input_arr[i]);
                    }
                    printf("area = %.2f\n", area);
                    printf("perimeter = %.2f\n", perimetr);

                    data_circle[ncircle].r = r;
                    data_circle[ncircle].x = atoi(x_arr);
                    data_circle[ncircle].y = atoi(y_arr);
                }
            }
        }
    }

    fclose(fptr);
    printf("\n");
    printf("----------------------------\n");
    print_intersects(ncircle, data_circle);

    return 0;
}