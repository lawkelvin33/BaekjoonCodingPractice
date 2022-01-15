#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int x[N],y[N], result[N];

    
    for(int i=0;i<N;i++){
        scanf("%d%d", &x[i], &y[i]);
        result[i] = 1;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(x[i]<x[j] && y[i]<y[j])
                result[i]++;
            else if(x[i]>x[j] && y[i]>y[j])
                result[j]++;
        }
    }
    for(int i=0;i<N;i++)
        printf("%d ", result[i]);
        
    return 0;
}
