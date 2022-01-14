#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int sum;
    int rem = N%5;
    int n5 = N/5;
    while(n5>0){
        if(rem%3!=0){
            rem += 5;
            n5 -= 1;
        }
        else{
            break;
        }
            
    }
    if(rem%3==0)
        sum = n5 + rem/3;
    else
        sum = -1;
        
    printf("%d", sum);
    return 0;
    
}
