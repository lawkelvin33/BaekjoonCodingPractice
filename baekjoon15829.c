#include<stdio.h>

int main(){
    char arr[51];
    int L;
    long long sum=0;
    long long ri;
    long long M = 1234567891;
    scanf("%d", &L);
    scanf("%s", arr);
    
    for(int i=0;i<L;i++){
        ri = 1;
        for(int j=0;j<i;j++){
            ri *= 31;
            ri %= M;
        }
        sum += ((arr[i]-96)*ri);
    }
    
    printf("%lld", sum%M);
    
    return 0;
    
}
