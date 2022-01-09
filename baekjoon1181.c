#include<stdio.h>
#include<string.h>

typedef struct{
    char string[51];
    int length;
} str;

str order[20000];
void mergesort(str*,int,int);
void merge(str*,int,int,int);

int main(){
    int N;
    scanf("%d", &N);
    str arr[N];
    for(int i=0;i<N;i++){
        scanf("%s", arr[i].string);
        arr[i].length = strlen(arr[i].string);
    }
    mergesort(arr,0,N-1);
    
    puts(arr[0].string);
    for(int i=1;i<N;i++){
        if(strcmp(arr[i].string,arr[i-1].string)!=0)
            puts(arr[i].string);
    }
    
    return 0;
    
}

void merge(str* arr, int first, int mid, int last){
    int i = first; //i와j는 두개의 sub arr를 비교할때 쓰고,
    int j = mid + 1; // k는 order에 쭉 정렬할때 사용됨.
    int k = first;
    
    while(i<=mid && j<=last){
        if(arr[i].length<arr[j].length)
            order[k++] = arr[i++];
        else if(arr[i].length>arr[j].length)
            order[k++] = arr[j++];
        else{
            if(strcmp(arr[i].string,arr[j].string)>0)
                order[k++] = arr[j++];
            else
                order[k++] = arr[i++];
        }
    }
    while(i<=mid)
        order[k++] = arr[i++];
    while(j<=last)
        order[k++] = arr[j++];
        
    for(int i=first;i<=last;i++)
        arr[i] = order[i];
}

void mergesort(str* arr, int first, int last){
    int mid = (first + last) / 2;
    if(first<last){
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}

