/*Gauss Elimination Method */
#include<stdio.h>
#include<math.h>
#define MAX 10
int main()
{
 printf("Sasank Lama \n");
 int i,j,k,n;
 float a[MAX][MAX],x[MAX],c,sumx;
 printf("Enter the no. of unknowns : ");
 scanf("%d",&n);
 printf("Enter %dx%d elements for tha augmented matrix:\n",n,n+1);
 for(i=1;i<=n;i++)
 for(j=1;j<=n+1;j++)
 scanf("%f",&a[i][j]);
 /*Elimination process*/
 for(k=1;k<=n-1;k++)
 {
 for(i=k+1;i<=n;i++)
 {
 c=a[i][k]/a[k][k];
 for(j=k;j<=n+1;j++)
 a[i][j]=a[i][j]-c*a[k][j];
 }
 }
 printf("\n The echelon form of matrix is: \n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n+1;j++)
 printf("%.2f\t",a[i][j]);
 printf("\n");
 }

 /*Backward Substituion*/
 x[n]=a[n][n+1]/a[n][n];
 for(i=n-1;i>=1;i--)
 { sumx=0;
 for(j=i+1;j<=n;j++)
 sumx+=x[j]*a[i][j];
 x[i]=(a[i][n+1]-sumx)/a[i][i];
 }
 printf("\n The solution set is: \n");
 for(i=1;i<=n;i++)
 printf("x[%d]=%.4f\t",i,x[i]);
return 0;
}
