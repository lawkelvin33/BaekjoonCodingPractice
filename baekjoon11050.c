#include<stdio.h>

int main(){
    int N,K;
    int num=1;
    int den=1;
    scanf("%d %d", &N, &K);
    
    for(int i=0;i<K;i++){
        num *= N--;
        den *= i+1;
    }
    printf("%d", num/den);
    
    return 0;
}
