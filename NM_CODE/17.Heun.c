#include<stdio.h>
#include<math.h>
#define f(x,y) (2*(y)/(x)) // 2y/x
int main()
{
 printf("Sasank Lama \n");
 float x,y,h,xp,m1,m2;
 int i,n;
 printf("Enter initial values of x and y: ");
 scanf("%f%f",&x,&y);
 printf("Enter x-value at which y is required: ");
 scanf("%f",&xp);
 printf("Enter step-size: ");
 scanf("%f",&h);
 n=((xp-x)/h);
 for(i=1;i<=n;i++)
 {
 m1=f(x,y);
 m2=f(x+h,y+(m1*h));
 x=x+h;
 y=y+(m1+m2)*h/2;
 }
 printf("\nThe value of y at x=%.2f is %.4f : ",x,y);
 return 0;
}
