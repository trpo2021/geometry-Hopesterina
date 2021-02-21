#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 10
#include <math.h>

int main()
{
    int r = 0;
    float s = 0, p = 0;
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

    char name_of_figure[6] = "Circle";
    int k = 0, t = 0;
    for(int i = 0; i < 6; i++)
    {
        if(input_arr[i] != name_of_figure[i])
        {
            k = k + 1;
            break;
        }
    }                                                // выполнили проверку имени фигуры
          
    for(int i = 7; i < 14; i++)                       // 4 10, 3
    {
        if((input_arr[i] != '0') && (input_arr[i] != '1') && (input_arr[i] != '2') && (input_arr[i] != '3') && (input_arr[i] !='4') && 
        (input_arr[i] != '5') && (input_arr[i] != '6') && (input_arr[i] != '7') && (input_arr[i] != '8') && (input_arr[i] != '9') && 
        (input_arr[i] != ',') && (input_arr[i] != ' ') && (input_arr[i] != ')') && (input_arr[i] != '('))
        {
            t = 1;
            break;
        } 
         
        
    }                                                // выполнили проверку того, что в скобках
        
    
    if (k > 0) 
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
        if (t == 1)
        {
            for(int i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
            printf("invalid values\n");
            printf("please correct\n");              // ошибка о значениях
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
                };

            }
            r = atoi(r_arr);

            s =  M_PI * r * r;

            p =  2 * M_PI * r;
       
            printf("\n");
            for(int i = 0; i < N; i++)
            {
                printf("%c", input_arr[i]);
            }
        
            printf("area = %.3f\n",s);
            printf("perimeter = %.3f\n",p); 
        }
        
    }
        

    return 0;
}
