#include<stdio.h>
//9의 거듭제곱마다 1씩 차이남.
int tree(int N, int bf){
    if(N==1)
        return 0;
    int two,thr;
    int min=100000;
    if(bf!=2)
        min = tree(N-1,bf+1);
    
    if(N%2==0){
        two = tree(N/2,0);
        if(min>two)
            min = two;
    }
    if(N%3==0){
        thr = tree(N/3,0);
        if(min>thr)
            min = thr;
    }
    return min + 1;
    
}
int main(){
    int N;
    int result=0;
    scanf("%d", &N);
    result = tree(N,0);
    printf("%d", result);
    return 0;
}
