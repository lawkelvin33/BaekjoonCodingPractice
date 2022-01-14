#include<stdio.h>

int main(){
    int sum=1;
    int i=1;
    int num;
    
    scanf("%d", &num);
    
    while(num>sum){
        sum += 6*(++i-1);
    }
    
    printf("%d", i);
    
    return 0;
    
}
