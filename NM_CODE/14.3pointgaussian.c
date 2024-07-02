/*Gaussian Integration for 3 points*/
#include<stdio.h>
#include<math.h>
#define f(x) (exp(pow(x,2)))

int main()
{
    printf("Sasank Lama \n");
    int i,n=3;
    float a,b,c,k[5],x[5],z[5],w[5],Ig=0;
    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);
    z[0]=-0.77460;
    z[1]=0;
    z[2]=-z[0];
    w[0]=w[2]=0.55556;
    w[1]=0.88889;
    c=(b-a)/2;
    for(i=0;i<n;i++)
        x[i]=c*z[i]+(b+a)/2;
    for(i=0;i<n;i++){
        k[i]=f(x[i]);
        Ig+=(w[i]*k[i]);
    }
    Ig=c*Ig;
    printf("\nThe integration is %f",Ig);
    return 0;
}
