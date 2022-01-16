#include<stdio.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int arr[N+1];
    int result[N];
    int j=1;
    
    if(K==1){
        printf("<");
        for(int i=1;i<N;i++)
            printf("%d, ", i);
        printf("%d>", N);
        return 0;
    }
    
    for(int i=1;i<N+1;i++)
        arr[i] = i+1;
    arr[N] = 1;
    
    for(int i=1;i<N+1;i++){//algorithm or O(kn)
        for(int a=0;a<K-2;a++)
            j = arr[j];
        result[i-1] = arr[j];//K번째는 외부에 저장되고 빠져나감.
        arr[j] = arr[arr[j]];//K-1번째는 K+1번째에 대응됨.
        j = arr[j];
    }
    printf("<");
    for(int i=0;i<N-1;i++){
        printf("%d, ", result[i]);
    }
    printf("%d>", result[N-1]);
    
    return 0;
}
