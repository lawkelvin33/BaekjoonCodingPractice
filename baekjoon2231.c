#include <stdio.h>
int main(){
int a;
int sum;
int tmp;
int i;
int result = 0;
scanf("%d", &a);
    for(i=0; i<a; i++){
        tmp = i;
        sum = 0;
        sum = sum + i;
            while(tmp>0){
                sum = sum + tmp%10;
                tmp = tmp / 10;
            }
        if(sum == a){
            result = i;
            break;
        }
    }
    printf("%d", result);
return 0;
}
