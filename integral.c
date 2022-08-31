#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

double Function(double x)
{
    double fx = x*x;

    return (fx);
}

double RandSum(double A, double B, int PARTITIONS);
double MiddleSum(double A, double B, int PARTITIONS);

int main()
{
    int PARTITIONS;
    double A, B;
    int runState = 1, T;

    while(runState)
    {       
        printf("\nTipo de operação:\n 1.Soma média\n 2.Soma randômica\n 3.Exit\n SELECT: ");
        scanf("%d", &T);
        if(T == 3)
        {
            runState = 0;
            continue;
        }

        printf("\nNúmero de Partições:");
        scanf("%d", &PARTITIONS);
        printf("\nNúmero de Início: ");
        scanf("%lf", &A);
        printf("\nNúmero de Fim: ");
        scanf("%lf", &B);
        
        switch(T)
        {
            case 1:
                printf("\n%.15f\n\n", MiddleSum(A, B, PARTITIONS));
                break;
            case 2:
                printf("\n%.15f\n\n", RandSum(A, B, PARTITIONS));
                break;
        }
    }

}

// Function: MiddleSum()
// Input:
//      A = Initial x
//      B = Final x
//      PARTITIONS = N of divisions in the interval [A,B]
//
// Output:
//      Sum from Function() * dx with x in interval[Ai, Bi] = (Bi - Ai) / 2. (Middle Element), with Bi - Ai = dx
//
double MiddleSum(double A, double B, int PARTITIONS)
{
    double sum = 0;
    double dx = (double)(B-A)/PARTITIONS;

    for(int i = 0; i < PARTITIONS; i++)
    {
        double x = A + dx * i + dx/2;
        sum += Function(x) * dx;
    }
    return sum;
}

// Function: RandSum()
// Input:
//      A = Initial x
//      B = Final x
//      PARTITIONS = N of divisions in the interval [A,B]
//
// Output:
//      Sum from Function() * dx with randomized x in interval[Ai, Bi], with Bi - Ai = dx
//
double RandSum(double A, double B, int PARTITIONS)
{
    srand(time(NULL));
    double sum = 0;
    double dx = (double)(B-A)/PARTITIONS;

    for(int i = 0; i < PARTITIONS; i++)
    {
        double rand_interval = ((float)rand() / RAND_MAX) * dx;
        double x = A + dx * i + rand_interval;
        sum += Function(x) * dx;
    }
    return sum;
}
