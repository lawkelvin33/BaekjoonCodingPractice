#include <stdio.h>

int main()
{
    int N;
    int i = 666;
    int n = 1;
    int tmp;
    scanf("%d", &N);
    
    
    while(n<N){
        i++;
        tmp = i;
        while(tmp>=666){
            if(tmp%1000==666){
                n++;
                break;
            }
            tmp /= 10;
        }
        
    }
    printf("%d", i);
        
        
    return 0;
}
