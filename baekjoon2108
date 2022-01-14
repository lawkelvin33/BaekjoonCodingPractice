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
    double mean;
    int max;
    int min;
    int median;
    int cnt=1;
    int cntMax=0;
    int maxCounter=0;
    int mode;
    int meanINT;
    
    int range;
    scanf("%d", &N);
    int arr[N];
    int cntArr[N];
    scanf("%d", &arr[0]); 
    max = arr[0];
    min = arr[0];
    mean = arr[0];
    for(int i=1;i<N;i++){
        scanf("%d", &arr[i]);
        mean += arr[i];
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    mode = arr[0];
    mergeSort(arr, N, 0, N-1);
    cntArr[0] = 1;
    for(int i=1;i<N;i++){ // cntArr 채우고 동시에 cntArr의 max값을 구함.
        if(arr[i] == arr[i-1])
            cntArr[i] = ++cnt;
        else{
            cnt = 1;
            cntArr[i] = cnt;
        }
        if(cntArr[i]>cntMax)
            cntMax = cntArr[i];
    }
    
    for(int i=0;i<N;i++){
        if(cntArr[i] == cntMax){
            if(maxCounter == 1){
                mode = arr[i];
                break;
            }
            else{
                maxCounter++;
                mode = arr[i];
            }
        }
    }           
    
    mean /= N;
    meanINT = round(mean);
    
    median = arr[N/2];
    range = max - min;
    
    printf("%d\n%d\n%d\n%d", meanINT, median, mode, range);
    
    
    return 0;
}

/*
이 문제에서 처음에 44%에서 틀린 반례가 발생하였다. 바로

mean을 double이 아닌 float형으로 선언하였기 때문에 발생한 문제이다. 

float형은 4byte, 32bit를 저장하는데, 이는 곧 1bit의 부호(sign), 8bit의 지수(exp), 23bit의 가수(mantissa)

이는 곧 2^23, 약 7자리수(-8,388,607~8,388,607)를 표현하는 것이 가능하다.

double형은 8byte, 64bit, 1bit의 부호(sign), 11bit의 지수(exp), 52bit의 가수(mantissa)

이는 곧 2^52, 약 15자리수 대략(-450,359,963,000,000~450,359,963,000,000)를 표현하는 것이 가능하다.

 

이번 문제에서 mean이 다룰 수 있는 최대의 값은 |4000| * 500,000 = |200,000,000| 이다.

즉, float가 표현할 수 있는 가수를 훨씬 넘어서버렸다.

따라서, float가 아닌 double형을 이용해야한다.

 

이러한 세세한 점을 신경쓰는 것이 귀찮다면 앞으로 실수를 다룰때는 double로 선언하는 습관을 갖도록 하자.
*/
