/*이 문제는 4분면 Search로 접근해야될거같다.*/
#include<stdio.h>
#include<math.h>

int main(){
    int N,r,c;
    int start=0;
    scanf("%d %d %d", &N, &r, &c);
    for(int i=N;i>0;i--){
        if(r<pow(2,i-1)){
            if(c<pow(2,i-1))//2사분면
                start = start; //별 의미 없지만 가독성을 위해 추가
            
            else{//1사분면
                start += pow(2,i-1)*pow(2,i-1);
                c -= pow(2,i-1);
            }
        }
        else{
            if(c<pow(2,i-1)){//3사분면
                start += pow(2,i-1)*pow(2,i-1)*2;
                r -= pow(2,i-1);
            }
            else{//4사분면
                start += pow(2,i-1)*pow(2,i-1)*3;
                r -= pow(2,i-1);
                c -= pow(2,i-1);
            }
        }
            
    }
    printf("%d", start);
}
