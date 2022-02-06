#include<stdio.h>
int arr[50][50];

int dfs(int i, int j, int M, int N){
    if(arr[i][j]==0)
        return 0;
    arr[i][j] = 0;
    if(i<N-1)//마지막 줄이 아닐 경우
        dfs(i+1,j,M,N);
    if(i>0)//첫번째 줄이 아닐 경우
        dfs(i-1,j,M,N);
    if(j>0)
        dfs(i,j-1,M,N);
    if(j<M-1)
        dfs(i,j+1,M,N);
    return 1;
}

int main(){
    int T,M,N,K;
    int x,y;
    int result;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d", &M, &N, &K);
        for(int j=0;j<N;j++){//배추밭 초기화
            for(int k=0;k<M;k++)
                arr[j][k] = 0;
        }
        for(int i=0;i<K;i++){
            scanf("%d %d", &x,&y);
            arr[y][x]++;
        }
        result = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==1)
                    result += dfs(i,j,M,N);
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
