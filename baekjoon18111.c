#include<stdio.h>

int main(){
    int  N,M;
    long long B;
    long long height[257]={0,};
    long long tim=0;
    int tmp;
    long long minTime = 0;
    int minHeight=0;
    long long b;
    int done;
    
    scanf("%d %d %lld", &N, &M, &B);
    b = B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &tmp);
            height[tmp]++;
        }
    }
    
    for(int i=256;i>=0;i--){
        minTime += 2*i*height[i];
    }
        
    
    for(int i=1;i<257;i++){//result height
        b = B;
        tim = 0;
        done = 1;
        for(int j=256;j>=0;j--){//블록들의 원래 높이
            if(i>j){//블록 추가
                tim += (i-j)*height[j];
                b -= (i-j)*height[j];
            }
            else if(i<j){//블록 제거
                tim += (j-i)*2*height[j];
                b += (j-i)*height[j];
            }
            if(b<0){
                done = 0;
                break;
            }
        }
        if(done==1 && minTime>=tim){
            minTime = tim;
            minHeight = i;
        }
    }
    
    printf("%lld %d", minTime, minHeight);
    return 0;
}

 
