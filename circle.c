#include <stdio.h>
#include <stdlib.h>
#define N 50
#include <math.h>

int main()
{
//    int x, y;
    int r;
    float s = 0, p = 0;
    FILE *fptr = NULL;

    char a[N] = {0};
    char arr[N] = {0};


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
            fscanf(fptr, "%c", &a[i]);
            ++i;
        }
    }

    fclose(fptr);     //записали строку из файла в массив а

    int j = 0;
    for(int i = 0; i < N-1; i++)                       // circle(2 10, 3)
    {
         if((a[i] == '(') || (a[i] == ' ') || (a[i] == ','))
         {
              arr[j] = a[i+1];
              j++;
         };
         if(a[i] == ')')
         {
              break;
         };

    }


    r = arr[3] - '0';
//    x = arr[0] - '0';
//    y = arr[1] - '0';


    s =  M_PI * r * r;

    p =  2 * M_PI * r;

    for(int i = 0; i < N; i++)
    {
        printf("%c", a[i]);

    }
    printf("area = %.2f\n",s);
    printf("perimeter = %.2f\n",p);


    return 0;
}
