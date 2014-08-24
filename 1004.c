/*************************************************************************
	> File Name: 1004.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月24日 星期日 18时55分47秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<assert.h>

static char stack[100];
static int stop = -1;
static char a[100];
static char b[100];
static int len;
static int num;
static int path[100];

char 
top()
{
    return stack[stop];
}

void
push(char ch)
{
    stop += 1;
    stack[stop] = ch; 
}

int
is_empty()
{
    return stop == -1;
}

void
pop()
{
    stop -= 1;
}

void
print()
{
    int i;
    char t;
    for (i = 0; i < 2*len; i++)
    {
        t = (path[i] == 1) ? 'i' : 'o';
        printf("%c ",t);
    }
    printf("\n");
}

void
dfs(int npush, int npop)
{
    char tmp;
    if (npush == len && npop == len)
    {
        print();
        return;
    }
    if (npush < len)
    {
        push(a[npush]);
        path[num++] = 1;
        dfs(npush+1,npop);
        num--;
        stop--;

    }
    if ((top() == b[npop]) && (!is_empty()))
    {                              //如果相等,两种情况。一种是pop出去，一种是继续push
        tmp = top();
        pop();
        path[num++] = 0;
        dfs(npush,npop+1);
        num--;
        push(tmp);
    }
}

int
main(void)
{
    while((scanf("%s",a)) != EOF)
    {
        scanf("%s",b);
        len = strlen(a);
        printf("[\n");
        dfs(0,0);
        printf("]\n");

    }
    return 0;
}
