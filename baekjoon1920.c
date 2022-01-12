#include<stdio.h>

void merge(int* A, int N, int low, int mid, int high){
    int order[N];
    int i = low;
    int j = mid + 1;
    int k = low;
    
    while(i<=mid && j<=high){
        if(A[i] < A[j])
            order[k++] = A[i++];
        else
            order[k++] = A[j++];
    }
    
    if(i<=mid)
        while(i<=mid)
            order[k++] = A[i++];
    if(j<=high)
        while(j<=high)
            order[k++] = A[j++];
    for(int i=low; i<=high; i++)
        A[i] = order[i];
}

void mergeSort(int* A, int N, int low, int high){
    if(low<high){
        int mid = (low + high) / 2;
        mergeSort(A, N, low, mid);
        mergeSort(A, N, mid+1, high);
        merge(A, N, low, mid, high);
    }
}

int binarySearch(int *A, int low, int high, int num){
    int mid = (low + high) / 2;
    if(low == high){
        if(A[mid]==num)
            return 1;
        else
            return 0;
    }
    if(num > A[mid])
        return binarySearch(A, mid+1, high, num);
    else if(num < A[mid])
        return binarySearch(A, low, mid, num);
    else
        return 1;
}


int main(){
    int N,M;
    int tmp;
    scanf("%d", &N);
    int A[N];
    int order[N];
    for(int i=0;i<N;i++)
        scanf("%d", &A[i]);
    mergeSort(A, N, 0,N-1);
   
    scanf("%d", &M);
    int B[M];
    for(int i=0;i<M;i++){
        scanf("%d", &tmp);
        if(binarySearch(A, 0, N-1, tmp))
            B[i] = 1;
        else
            B[i] = 0;
    }
    
    for(int i=0;i<M;i++)
        printf("%d\n", B[i]);
        
    return 0;
}
