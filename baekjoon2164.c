#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int arr[N];
    int tmp;
    int c;
    for(int i=0;i<N;i++)
        arr[i] = i+1; //arr[0] = 1, arr[1] = 2, ... arr[n-1] = n
    tmp = N;
    while(tmp>1){
        if(tmp % 2 == 1){ //홀수일 경우
            
            tmp /= 2;
            c = arr[1];
            for(int i=0;i<tmp-1;i++){
                arr[i] = arr[(i+1)*2+1];
            }
            arr[tmp-1] = c;
        }
        else{//짝수인 경우
            tmp /= 2;
            for(int i=0;i<tmp;i++){
                arr[i] = arr[i*2+1];
            }

            
        }
            
    }
    printf("%d", arr[0]);
    
    return 0;
}



/*=> 기준은 전꺼
홀->짝 (맨뒤)
홀->홀 (맨뒤)
짝->짝 (정렬)
짝->홀 (정렬)
홀수일때는 2번째가 맨뒤, 나머지는 정렬됨.
짝수일때는 전부 정렬.
*/
