#include<stdio.h>
int main(){
    
    int a,b;
    int i=2;

    scanf("%d %d", &a, &b);
    int tmpA;
    int tmpB;
    int max=1;
    int min=1;
    tmpA = a;
    tmpB = b;
    //소인수 분해
    
    while(tmpA>1 && tmpB>1){
        if(tmpA%i==0 && tmpB%i==0){ // 최대공약수구하기
            max *= i;
            min *= i;
            tmpA /= i;
            tmpB /= i;
        }
        else if(tmpA%i==0 && tmpB%i!=0){
            min *= i;
            tmpA /= i;
        }
        else if(tmpA%i!=0 && tmpB%i==0){
            min *= i;
            tmpB /= i;
        }
        else
            i++;
    }
    if(tmpA>1)
        min*=tmpA;
    else if(tmpB>1)
        min*=tmpB;
        

    printf("%d\n%d", max, min);
    
    
    return 0;
}
