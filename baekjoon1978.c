#include<stdio.h>
int isPrime(int num){
    int cnt=0;
    if(num==1 || num==4)
        return 0;
    for(int i=2;i<num/2;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int N;
    scanf("%d", &N);
    int tmp;
    int cnt=0;
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        if(isPrime(tmp))
            cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
    
}
