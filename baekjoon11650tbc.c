#include<stdio.h>
void merge(int N, int* x, int* y, int* order, int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int tmp[N];
    
    while(i<=mid && j<=high){
        if(x[i]<x[j])
            tmp[k++] = order[i++];
        else if(x[i]>x[j])
            tmp[k++] = order[j++];
        else{
            if(y[i]<y[j])
                tmp[k++] = order[i++];
            else
                tmp[k++] = order[j++];
        }
    }
    if(i<=mid)
        while(i<=mid)
            tmp[k++] = order[i++];
    if(j<=high)
        while(j<=high)
            tmp[k++] = order[j++];
    for(int i=low;i<=high;i++)
        order[i] = tmp[i];
}
void mergeSort(int N, int* x, int* y, int* order, int low, int high){
    int mid = (low + high) / 2;
    if(low<high){
        mergeSort(N,x,y,order,low,mid);
        mergeSort(N,x,y,order,mid+1,high);
        merge(N,x,y,order,low,mid,high);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int x[N];
    int y[N];
    int order[N];
    for(int i=0;i<N;i++){
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
        order[i] = i;
    }
    mergeSort(N,x,y,order,0,N-1);
    
    for(int i=0;i<N;i++)
        printf("%d %d\n", x[order[i]], y[order[i]]);
    
    
    return 0;
}
