//Newton Raphson Method
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
#define E 0.0001
#define f(x) (exp(x)-x-2)
#define f1(x) (exp(x)-1)
int main()
{   int count=1;
    printf("Sasank Lama \n");
    float x0,x1;
    printf("Enter the initial guess value. ");
    scanf("%f",&x0);
    if(f1(x0)==0)
        printf("Derivative is zero at guess value.");
    else
    {   begin:
        x1=x0-(f(x0)/f1(x0));
        if(fabs((x1-x0)/x1)<E)
        {
            printf("The root is %f",x1);
            printf("\nNo. of iterations is %d",count);
        }
        else
        {
            x0=x1;
            count++;
            if(count<MAX) goto begin;
            else
                printf("The process doesn\'t converge.");
        }
    }
    return 0;
}
