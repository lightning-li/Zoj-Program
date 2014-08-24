/*************************************************************************
	> File Name: 1005.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月24日 星期日 23时10分50秒
 ************************************************************************/

#include<stdio.h>

int
main(void)
{
    int a,b,n;
    int tempa ;
    int tempb ;
    while((scanf("%d%d%d",&a,&b,&n)) != EOF)
    {
        tempa = 0;
        tempb = 0;
        while(1)
        {
            if (tempa == 0)
            {
                printf("fill A\n");
                tempa += a;
            }
            if (tempb != b)
            {
                printf("pour A B\n");
                if (tempa + tempb >= b)
                {
                    tempa = tempb + tempa -b;
                    tempb = b;
                }
                else
                {
                    tempb += tempa;
                    tempa = 0;
                }
                if (tempb == n)
                    break;
            }
            else
            {
                printf("empty B\n");
                tempb = 0;
            }
        }
        printf("success\n");
    }
    return 0;
}
