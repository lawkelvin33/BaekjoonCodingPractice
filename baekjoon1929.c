#include<stdio.h>

int main(){
    long long arr[1000001] = {0,};
    long long N,M;
    scanf("%lld %lld", &M, &N);
    for(long long i=0;i<=N;i++)
        arr[i] = 0;
    for(long long i=2;i<=N;i++){
        if(arr[i]==0)
            for(long long j=i;i*j<=N;j++)
                arr[i*j] = 1;
            
    }
    arr[1] = 1;
    for(int i=M;i<=N;i++)
        if(arr[i]==0){
            printf("%d\n", i);
        }
    
    return 0;
    
}
