#include<stdio.h>

int main(){
    int K, N;
    
    int arr[10001];
    long long max=0;
    int cnt;
    int i,j;
    int ans=0;
    long long low, mid;
    scanf("%d %d", &K, &N);
    for(i=0;i<K;i++){
        scanf("%d", &arr[i]);
        if(max<arr[i])
            max = arr[i];
    }
    low = 1;
    while(low<=max){
        cnt = 0;
        mid = (low + max) / 2;
        for(j=0;j<K;j++)
            cnt += arr[j]/mid;
        if(cnt<N) //랜선의 길이가 더 작아야되면
            max = mid - 1;
        else{ // 랜선의 길이가 더 커야되면 or 딱맞으면
            low = mid + 1;
            if(ans<mid)
                ans = mid;
        }
                
    }
   
    
    printf("%d", ans);
    
    
    
    return 0;
}
