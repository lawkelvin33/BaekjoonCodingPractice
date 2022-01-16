#include<stdio.h>

int main(){
    int a,b,v;
    int result;
    scanf("%d %d %d", &a, &b, &v);
    
    if(a>=v)
        result = 1;
    else{
        result = (v-a)/(a-b) + 1;
        if((v-a)%(a-b)!=0)
            result++;
    }
    

    printf("%d", result);
    
    
    return 0;
}
