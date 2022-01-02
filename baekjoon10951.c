#include<stdio.h>
#include<stdlib.h>
int main()
{

    int result[1000];
    int a,b;
    int i=0;

    
    while(scanf("%d %d", &a, &b) != -1){
        result[i++] = a + b;
    }
    for(int j=0;j<i;j++)
        printf("%d\n", result[j]);
    return 0;
}
