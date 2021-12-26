#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    float* arr;
    float* arrL;
    float max=0;
    float sum=0;
    
    scanf("%d", &N);
    arr = (float*)malloc(sizeof(float)*N);
    arrL = (float*)malloc(sizeof(float)*N);
    for(int i=0;i<N;i++){
        scanf("%f", &arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }
    for(int i=0;i<N;i++){
        arrL[i] = (arr[i]/max)*100;
        sum = sum + arrL[i];
    }
    
    printf("%f", sum/N);

    return 0;

}
