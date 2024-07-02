/*Gauss Seidel Method*/
#include<stdio.h>
#include<math.h>
#define MAX 10
#define E 0.0001
#define N 100
int main()
{
 printf("Sasank Lama \n");
 int i,j,k,n;
 float a[MAX][MAX],x[MAX],x0[MAX],sum1,sum2;
 printf("Enter the no. of unknowns : ");
 scanf("%d",&n);
 printf("Enter %dx%d elements for tha augmented matrix:\n",n,n+1);
 for(i=1;i<=n;i++)
 for(j=1;j<=n+1;j++)
 scanf("%f",&a[i][j]);
 for(i=1;i<=n;i++)
 x0[i]=0;
 for(k=1;k<=N;k++)
 {
 for(i=1;i<=n;i++)
 { sum1=sum2=0;
 for(j=1;j<=i-1;j++)
 sum1+=a[i][j]*x[j];
 for(j=i+1;j<=n;j++)
 sum2+=a[i][j]*x0[j];
 x[i]=(-sum1-sum2+a[i][n+1])/a[i][i];
 printf("%.3f\t",x[i]);
 }
 printf("\n");
 if((fabs(x[1]-x0[1])/x[1])<E)
 break;
 for(i=1;i<=n;i++)
 {
 x0[i]=x[i];
 }
 }
 if(k==N+1)
 printf("Maximum number of iterations exceeded.");
 else{
 printf("The solution set is:\n");
 for(i=1;i<=n;i++)
 printf("x[%d]=%.3f\n",i,x[i]);
 }
 printf("The no. of iteration: %d",k);
 return 0;
}
