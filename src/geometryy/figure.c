#include <libgeometry/for_checking.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define N 50

int main()
{
    float radius = 0;
    float area = 0, perimetr = 0;
    char  r_arr[N];
    char input_arr[N] = {0};

    FILE *fptr = NULL;

    fptr = fopen("input.txt", "r");
    if (!fptr)
    {
        printf("Can`t open the file\n");
    }
    else
    {
        int i = 0;

        while (i < N)
        {
            fscanf(fptr, "%c", &input_arr[i]);
            ++i;
        }
    }

    fclose(fptr);     //записали строку из файла в массив а

    
    int counter_1 = name_verification(input_arr);
    int counter_2 = checking_parameters_figure(input_arr);
    
    if (counter_1 > 0) 
    {
        for(int i = 0; i < N; i++)
        {
            printf("%c", input_arr[i]);
        }
        printf("incorrect name of figure\n");
        printf("please correct\n");              // ошибка об имени
        
    }
    else
    {
        if (counter_2 > 0)
        {
            for(int i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
            printf("invalid values\n");
            printf("please correct\n");              // ошибка о параметрах фигуры
        }
        else
        {
            for (int i = 0; i < N; i++) 
            {
                if ((input_arr[i] == ',') && (input_arr[i + 1] == ' ')) 
                {
                    for (int k = i; input_arr[k + 1] != ')'; k++) 
                    {
                        r_arr[k - i] = input_arr[k + 1];
                    }
                }

            }

            radius = atof(r_arr);

            area =  M_PI * radius * radius;

            perimetr =  2 * M_PI * radius; 
       
            printf("\n");
            for(int i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
        
            printf("area = %.3f\n",area);
            printf("perimeter = %.3f\n",perimetr); 
        }
        
    } 

    return 0;
}