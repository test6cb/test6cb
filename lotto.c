#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
#define szelvenyDB 100000000

int in_array(int * arr, int size, int number);
void sort(int * arr, int * arr_end);
int sorsol(int * arr, int size);

int main(int argc, char ** argv)
{
    srand(time(NULL));
    int nyeroszamok[SIZE] = {0,0,0,0,0};

    int i,j, talalatok[SIZE+1] = {0,0,0,0,0,0};
    sorsol(nyeroszamok, SIZE); //nyeroszamok sorsolasa
    for (i=0; i<SIZE; ++i)
        printf("%d;", nyeroszamok[i]);
    printf("\n==============\n");
    //kitoltok legeneralasa:
    for (i=0; i<szelvenyDB; ++i)
    {
       int szelveny[SIZE];
       sorsol(szelveny, SIZE);
       //talalatok osszeszamolasa:
       int talalat = 0;
       for (j=0; j<SIZE; ++j)
       {
           //adott szelveny talalatai:
           if (in_array(nyeroszamok, SIZE, szelveny[j]) )
             ++talalat;
       }
       //talalatok osztalyozasa:
       ++talalatok[talalat];
    }

    for (i=0; i<SIZE+1; ++i)
        printf("%d. talalat: %7d %f%%\n", i, talalatok[i], (double)100*talalatok[i]/szelvenyDB);
    return 0;
}

/** Megvizsgalja, hogy a tombben van-e a megadott szam */
int in_array(int * arr, int size, int number)
{
    int index = 0;
    while (index < size)
    {
        if (number== arr[index])
            return 1;
        ++index;
    }
    return 0;
}

/** Tomb rendezo fuggveny */
void sort(int * arr, int * arr_end)
{
    int * i, *j;
    for (i=arr; i!=arr_end; ++i)
    {
        for (j=i;j!=arr_end; ++j)
        {
            if (*i > *j)
            {
                int tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}

/** megadott kulonbozo szamot sorsol a megadott tombbe */
int sorsol(int * arr, int size)
{
    int i, r = rand()%90+1;
    for (i=0; i<size; ++i)
    {
        while ( in_array(arr, size, r) )
        {
            r = rand()%90+1;
        }
        arr[i] = r;
    }
    sort(arr, arr+size);
}
