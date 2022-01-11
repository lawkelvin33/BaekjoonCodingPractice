#include<stdio.h>

int bSearch(int*, int, int);
void mergeSort(int*,int*,int,int);
void merge(int*,int*,int,int,int);

int main(){
    int N,M;
    scanf("%d", &N);
    int A[N];
    int order[N];
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    int B[M];
    for(int i=0;i<M;i++){
        scanf("%d", &B[i]);
    }
    
    mergeSort(A,order,0,N-1);
    
    for(int i=0;i<M;i++){
        if(bSearch(A, N, B[i]))
            printf("1\n");
        else
            printf("0\n");
    }
    
    return 0;
    
}

int bSearch(int* A, int N, int num){
    int high = N-1;
    int low = 0;
    int mid;
    while(low<high){
        mid = (low + high) / 2;
        if(num>A[mid]){
            low = mid + 1;
        }
        else if(num<A[mid])
            high = mid - 1;
        else
            return 1;
    }
}

void mergesort(int* arr, int* order, int low, int high){
    int mid = (low + high) / 2;
    if(low<high){
        mergesort(arr, order,low, mid);
        mergesort(arr, order,mid+1, high);
        merge(arr, order,low, mid, high);
    }
}

void merge(int* arr, int* order, int low, int mid, int high){
    int i=low;
    int j = mid+1;
    int k = low;
    
    while(i<=mid && j<=high){
        if(arr[i]<arr[j])
            order[k++] = arr[i++];
        else
            order[k++] = arr[j++];
    }
    if(i<=mid)
        while(i<=mid){
            order[k++] = arr[i++];
        }
    else if(j<=high)
        while(j<=high){
            order[k++] = arr[j++];
        }
    for(i=low;i<=high;i++)
        arr[i] = order[i];
}
