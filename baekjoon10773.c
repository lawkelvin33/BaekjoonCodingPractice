#include<stdio.h>

int main(){
    int k;
    int arr[100000];
    int sum=0;
    int tmp;
    int i=-1;
    scanf("%d", &k);
    for(int j=0;j<k;j++){
        scanf("%d", &tmp);
        if(tmp==0){
            if(i>-1)
                sum -= arr[i--];
        }
        else{
            sum += tmp;
            arr[++i] = tmp;
        }
        
    }
    printf("%d", sum);
    return 0;
}
