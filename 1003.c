/*************************************************************************
	> File Name: 1003.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月24日 星期日 15时20分49秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int flag1,flag2;   //表示n,m是否已成功被分解

void
dfs(int n,int m,int fac)
{
    if (flag1)
        return;
    if (n == 1 && m == 1)
    {
        flag1 = 1;
        flag2 = 1;
        return;
    }
    if (m == 1)
    {
        flag2 = 1;
    }
    if (fac < 2)
        return;

    if (n%fac == 0)
        dfs(n/fac,m,fac-1);
    if (m%fac == 0)
        dfs(n,m/fac,fac-1);
    dfs(n,m,fac-1);
}

int
main(void)
{
    long a,b,tmp;
    while((scanf("%ld %ld",&a,&b)) != EOF)
    {
        flag1 = 0;
        flag2 = 0;
        if (a < b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        dfs(a,b,100);
        if ( flag1 || !flag2 ) //小数能被分解，大数不能被分解
            printf("%ld\n",a);
        else
            printf("%ld\n",b);
    }
    return 0;
}
