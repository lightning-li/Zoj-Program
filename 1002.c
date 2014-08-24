/*************************************************************************
	> File Name: 1002.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月24日 星期日 10时48分57秒
 ************************************************************************/

#include<stdio.h>

static int max;
static int q[4][4];
static int num;

int
find(int i, int j, int value)
{
    int m,n;
    for (m = j-1; m >=0; m--)
    {
        if (q[i][m] == 1)
            return 0;
        if (q[i][m] == 2)
            break;
    }
    for (m = i-1; m >= 0; m--)
    {
        if (q[m][j] == 1)
            return 0;
        if (q[m][j] == 2)
            break;
    }
    for ( m = j+1; m < value; m++ )
    {
        if (q[i][m] == 1)
            return 0;
        if (q[i][m] == 2)
            break;
    }
    for ( m = i+1; m < value; m++ )
    {
        if (q[m][j] == 1)
            return 0;
        if (q[m][j] == 2)
        break;
    }
    return 1;
}

void
maxmethods(int value)
{
    if (num > max)
        max = num;
    int i,j;
    for (i = 0; i < value;i++)
        for (j = 0; j < value; j++)
        {
            if (!q[i][j] && find(i,j,value))
            {
                q[i][j] = 1;
                num++;
                maxmethods(value);
                q[i][j] = 0;
                num--;
            }
        }
}

int
main(void)
{
    int value;
    int i,j;
    char ch;
    scanf("%d",&value);
    while(value != 0)
    {
        getchar();
        for (i = 0; i < value; i++)
        {
            for (j =0 ; j < value; j++)
            {
                scanf("%c",&ch);
                q[i][j] = (ch == 'X' ? 2 : 0);
            }
            getchar();
        }
        maxmethods(value);
        printf("%d\n",max);
        num = 0;
        max = 0;
        scanf("%d",&value);
    }
    return 0;
}
