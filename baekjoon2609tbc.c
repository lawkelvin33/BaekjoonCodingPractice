#include<stdio.h>
int main(){
    
    int a,b;
    int i=2;
    int j;
    int corA=1;
    int corB=1;
    int arrA[10000], arrB[10000];
    scanf("%d %d", &a, &b);
    int tmpA;
    int tmpB;
    int max;
    int min
    tmpA = a;
    tmpB = b;
    while(tmpA>1 || i>a/2){
        if(tmpA%i==0){
            arrA[corA++] = i;
        }
        else
            i++;
            
    }
    arrA[corA] = a;
    arrA[0] = 1;
    
    i = 2;
    
    while(tmpB>1 || i>b/2){
        if(tmpB%i==0){
            arrB[corB++] = i;
        }
        else
            i++;
            
    }
    arrB[corB] = b;
    arrB[0] = 1;
    
    i = corA;
    j = corB;
    while(i>=0 && j>=0){
        if(arrA[i]>arrB[j])
            i--;
        else if(arrA[i]<arrB[j])
            j--;
        else{
            max = arrA[i];
            break;
        }
            
    }///////여기까지가 최대공약수 구하기
    i = 0;
    j = 0;
    while(i<=corA && j<=corB){
        
    }
    
    
    
    return 0;
}
