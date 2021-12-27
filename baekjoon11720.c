#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    int sum=0;
    char* arr;
    scanf("%d", &N);
    arr = (char*)malloc(sizeof(char)*N);
    for(int i=0;i<N+1;i++){
        scanf("%c", &arr[i]);
    }
    
    for(int i=0;i<N+1;i++){
        switch(arr[i]){
            case '1':
                sum += 1;
                break;
            case '2':
                sum +=2;
                break;
            case '3':
                sum +=3;
                break;
            case '4':
                sum +=4;
                break;
            case '5':
                sum +=5;
                break;
            case '6':
                sum +=6;
                break;
            case '7':
                sum +=7;
                break;
            case '8':
                sum +=8;
                break;
            case '9':
                sum +=9;
                break;
            default:
                break;
        }
    }
    printf("%d", sum);
    free(arr);
    return 0;
}
