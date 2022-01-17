#include<stdio.h>

typedef struct{
    int age;
    char name[101];
    int reg;
}member;

member mem[100000]; 
int order[100000];
int N;
void merge(int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int tmp[N];
    
    while(i<=mid && j<=high){
        if(mem[order[i]].age<mem[order[j]].age)
            tmp[k++] = order[i++];
        else if(mem[order[i]].age>mem[order[j]].age)
            tmp[k++] = order[j++];
        else{
            if(mem[order[i]].reg<mem[order[j]].reg)
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
    for(int a=low;a<high+1;a++)
        order[a] = tmp[a];
}

void mergeSort(int low, int high){
    int mid = (low + high)/2;
    if(low<high){
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &mem[i].age);
        scanf("%s", mem[i].name);
        mem[i].reg = i;
        order[i] = i;
    }
    
    mergeSort(0,N-1);
    
    for(int i=0;i<N;i++){
        printf("%d ", mem[order[i]].age);
        puts(mem[order[i]].name);
    }
    
    
    
    return 0;
}
