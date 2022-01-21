#include<stdio.h>
void merge(int* arr, int* orderN, int low, int mid, int high, int N){
    int i=low;
    int j=mid+1;
    int k=low;
    int tmp[N];
    int order[N];
    
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            order[k] = orderN[j];
            tmp[k++] = arr[j++];
        }
        else{
            order[k] = orderN[i];
            tmp[k++] = arr[i++];
        }
    }
    if(i<=mid)
        while(i<=mid){
            tmp[k] = arr[i];
            order[k++] = orderN[i++];
        }
    if(j<=high)
        while(j<=high){
            tmp[k] = arr[j];
            order[k++] = orderN[j++];
        }
    
    for(int a=low;a<=high;a++){
        arr[a] = tmp[a];
        orderN[a] = order[a];
    }
    
}
void mergeSort(int* arr, int* orderN, int low, int high, int N){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(arr,orderN,low,mid,N);
        mergeSort(arr,orderN,mid+1,high,N);
        merge(arr,orderN,low,mid,high,N);
    }
}

int main(){
    int N,M;
    int i,j;
    scanf("%d", &N);
    int arrN[N];
    int orderN[N];
    for(i=0;i<N;i++){
        scanf("%d", &arrN[i]);
        orderN[i] = i;
    }
    scanf("%d", &M);
    int arrM[M];
    int orderM[M];
    int result[M];
    int cnt=0;
    for(i=0;i<M;i++){
        scanf("%d", &arrM[i]);
        orderM[i] = i;
    }
        
    
    mergeSort(arrN,orderN,0,N-1,N);//ascending order
    mergeSort(arrM,orderM,0,M-1,M);
    
    i=0;
    j=0;
    while(i<N && j<M){
        if(arrN[i] >arrM[j]){
            result[orderM[j++]] = cnt;
            if(j<M)
                if(arrM[j]!=arrM[j-1])
                    cnt = 0;
        }
        else if(arrN[i]<arrM[j])
            i++;
        else{ //일치하는 숫자 찾음.
            cnt += 1;
            i++;
        }
    }
    if(j<M)
        result[orderM[j++]] = cnt;

    while(j<M){
        if(arrM[j]!=arrM[j-1])
            cnt=0;
        result[orderM[j++]] = cnt;
    }
    for(int i=0;i<M-1;i++)
        printf("%d ", result[i]);
    printf("%d", result[M-1]);
        
    return 0;
}
