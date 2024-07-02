//Bisection Method
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
#define E 0.00001
#define f(x) (x*x-4*x-10)
int main(){
    printf("Sasank Lama \n");
    int count=0;
    float x1,x2,x0;
    printf("Enter the inital guess values x1 and x2\n");
    scanf("%f%f",&x1,&x2);
    if(f(x1)*f(x2)>0)
        printf("The guess values don\'t bracket root. Change the guess values.");
    else
    {   begin:
        x0=(x1+x2)/2;
        if(fabs(f(x0))<E)
        {
            printf("\nThe root is %f",x0);
            printf("\nNo. of iterations is %d",count);
        }
        else{
            if(f(x0)>0){
            x2=x0;
            count++;}
            else if(f(x0)<0){
            x1=x0;
            count++;}
            if (count<MAX)goto begin;
            else printf("\nThe process doesn\'t converge.");
        }
    }
    return 0;
}

