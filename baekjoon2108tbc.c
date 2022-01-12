#include<stdio.h>
#include<math.h>
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

int main(){
    
    int N;
    float mean = 0;
    int max = 0;
    int min = 0;
    int median;
    int range;
    scanf("%d", &N);
    int arr[N];
    scanf("%f", &arr[0]); 
    max = arr[0];
    min = arr[0];
    median += arr[0];
    for(int i=1;i<N;i++){
        scanf("%f", &arr[i]);
        mean += arr[i];
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    mean /= N;
    mean = round(mean);
    mergeSort(arr, N, 0, N-1);
    median = arr[N/2];
    range = max - min;
    
    printf("%d\n%d\n%d\n%d", mean, median, )
    
    
    return 0;
}
