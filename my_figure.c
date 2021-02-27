#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define N 50

int main()
{
    int radius = 0;
    float area = 0, perimetr = 0;
    char  r_arr[N];
    char input_arr[N] = {0};
    char name_of_figure[6] = "Circle";

    int i, j, k, t;           // вспомогательные переменные
    FILE *fptr = NULL;

    fptr = fopen("input.txt", "r");
    if (!fptr)
    {
        printf("Can`t open the file\n");
    }
    else
    {
        i = 0;

        while (i < N)
        {
            fscanf(fptr, "%c", &input_arr[i]);
            ++i;
        }
    }

    fclose(fptr);     //записали строку из файла в массив а

    
    k = 0;
    for(i = 0; i < 6; i++)
    {
        if(input_arr[i] != name_of_figure[i])
        {
            k = k + 1;
            break;
        }
    }                                               // выполнили проверку имени фигуры

    j = 7;
    t = 0;                                         
    while (input_arr[j] != ' ')
    {
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '1')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
        {
            t++;
            break;      
        }
        else
        {    
            j++;
        }    
    }
    

    while ((input_arr[j] != ',') && (input_arr[j + 1] != ' '))
    {
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '1')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
        {
            t++;
            break;         
        }
        j++;
        
    
    } 

    if (input_arr[j + 1] != ' ')
    {
        t++;
    }

    j++;
    
    while (input_arr[j] != ')')
    {
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '1')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
        {
            t++;
            break;          
        }
        else
        { 
            j++;
        }            
    }
    
   // Выполнили проверку параметров фигуры
    
    if (k > 0) 
    {
        for(i = 0; i < N; i++)
        {
            printf("%c", input_arr[i]);
        }
        printf("incorrect name of figure\n");
        printf("please correct\n");              // ошибка об имени
        
    }
    else
    {
        if (t > 0)
        {
            for(i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
            printf("invalid values\n");
            printf("please correct\n");              // ошибка о параметрах фигуры
        }
        else
        {
            for (i = 0; i < N; i++) 
            {
                if ((input_arr[i] == ',') && (input_arr[i + 1] == ' ')) 
                {
                    for (k = i; input_arr[k + 1] != ')'; k++) 
                    {
                        r_arr[k - i] = input_arr[k + 1];
                    }
                }

            }

            radius = atoi(r_arr);

            area =  M_PI * radius * radius;

            perimetr =  2 * M_PI * radius; 
       
            printf("\n");
            for(i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
        
            printf("area = %.3f\n",area);
            printf("perimeter = %.3f\n",perimetr); 
        }
        
    } 

    return 0;
}
