#include <stdio.h>

int binarySearch(long long* arr, int low, int high, int N, long long M){
    int mid = (low + high) / 2;
    long long sum = 0;
    for(int i=0;i<N;i++){
            if(arr[i]>mid)
                sum+=arr[i]-mid;
        }
    if(low<high){
        if(M>sum)
            return binarySearch(arr,0,mid-1,N,M);
        else if(M<sum)
            return binarySearch(arr,mid+1,high,N,M);
        else
            return mid;
    }
    //low==high
    if(M>sum)
        return mid-1;
    else
        return mid;
}

int main()
{
    int N;
    long long M;
    long long sum;
    long long h;
    long long max;
    scanf("%d %lld", &N, &M);
    
    long long arr[N];
    scanf("%lld", &arr[0]);
    max = arr[0];
    for(int i=1;i<N;i++){
        scanf("%lld", &arr[i]);
        if(max<arr[i])
            max = arr[i];
    }
    
    h = binarySearch(arr,0,max-1,N,M);
    
    printf("%lld", h);
    

    return 0;
}
