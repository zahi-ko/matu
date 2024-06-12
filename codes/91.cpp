#include<stdio.h>
int main()
{
    int i;
    double e=1.0,x,n,pro=1.0,fac=1.0;
    scanf("%lf %lf",&x,&n);
    if(n<=0) printf("error\n");
    else
    {
        for(i=1;i<=n;i++)
        {
            pro*=x;
            fac*=i;
            e+=pro/fac;
        }
        printf("%.6lf",e);
    }
    return 0;
}