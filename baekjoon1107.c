#include<stdio.h>
#include<stdlib.h>
int N;
int err[10] = {1,1,1,1,1,1,1,1,1,1};
//return 값은 최솟값, 
int dfs(int num,int dec){
    int n = (N/dec)%10; //이번자리수의 값
    int tmp;
    int min = 499900;
    if(dec>1){
        for(int i=0;i<=9;i++){
            if(err[(n+i)%10]==1){
                tmp = dfs(num+((n+i)%10)*dec,dec/10) + 1;
                if(tmp<min)
                    min = tmp;
            }
        }
    }
    
    else{
        for(int i=0;i<=9;i++)
            if(err[i]==1)
                if(min>abs(N-i-num))
                    min = abs(N-i-num) + 1;
    }
    return min;
}

int main(){
    int M,tmp,min[3];
    int i = 0;
    int dec = 1;
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        scanf("%d", &tmp);
        err[tmp] = 0;
    }
    tmp = N;
    while(tmp>=10){
        i++;
        tmp/=10;
    }
    for(int j=0;j<i;j++){
        tmp *= 10;
        dec *= 10;
    }
    min[0] = dfs(0,dec);
    if(err[1]==1){
        min[1] = dfs(dec*10,dec) + 1;
        if(min[1]<min[0])
                min[0] = min[1];
    }
    if(dec>=10){
        min[2] = dfs(0,dec/10);
        if(min[2]<min[0])
            min[0] = min[2];
    }
    printf("%d", min[0]<abs(N-100) ? min[0] : abs(N-100));
    
    return 0;
    }



/*

이번 문제는 일단 상당히 많은 시행착오를 겪어서 풀어냈다...

결국에는 핵심 문제는 if(err[(n+i)%10]==1)에서 가까운 값 2개 골라내면 나머지는 탐색하지 않는 알고리즘에 반례가 발생하여 문제가 생긴 것이다. 가까운 값 2개 혹은 일치하는 값 1개 포함 총 2~3개만 탐색하지 않고 10개 전부 탐색하였더니 정답이었다.



이번 문제는 경우의 수가 꽤 많이 붙는다.

n자리수가 주어질때

i)n-1자리수일때 // 2자리수 이상일 때 사용 가능

ii)n자리수일때

iii)n+1자리수일때 // 1버튼이 살아있을때만 사용 가능

등 3가지 경우의 수가 존재하고,

이 3가지를 각각 dfs 돌리는데, 각 자리수마다 부서진 버튼을 제외한 모든 숫자를 탐색해봐야한다.

결국 부서진 경우 빼고 모든 경우를 돌려보고

이중에서 가장 작은 값을 고르고,

이 또한 단순히 +,- 버튼만 이용하는 것과 비교하여 min값을 구하는 것이다.



일단 나의 dfs 알고리즘이 4ms가 나왔는데, 채점현황을 보니 0ms도 존재한다.

나중에 ps실력을 더 갈고 닦아서 0ms에 도전해보자!.*/
