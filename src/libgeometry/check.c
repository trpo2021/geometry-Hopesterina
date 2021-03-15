#include "for_checking.h"
#include <stdio.h>
#include <stdlib.h>

int name_verification(char* input_arr)
{
    char name_of_figure[6] = "Circle";
    int k = 0;
    for(int i = 0; i < 6; i++)
    {
        if(input_arr[i] != name_of_figure[i])
        {
            k = k + 1;
            break;
        }
    }     
    return k;
}

int checking_parameters_figure(char* input_arr)
{
    int j = 7;     //индекс значения после "("
    int t = 0;     //вспомогательная переменная

    if (input_arr[j] == ' ')
    {
        t++;
    }                                       
    while (input_arr[j] != ' ')
    {
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
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
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
        {
            t++;
            break;         
        }
        else
        {
            j++;
        }       
    
    } 
 
    if (input_arr[j + 1] != ' ')
    {
        t++;
    }

    j++;
 
    while (input_arr[j] != ')')
    {
        if ((input_arr[j] != '-') && (!(((input_arr[j] <= '9') && (input_arr[j] >= '0')) || (input_arr[j] == '.'))) && (input_arr[j] != ' '))
        {
            t++;
            break;          
        }
        else
        { 
            j++;
        }            
    }
    return t;
}
