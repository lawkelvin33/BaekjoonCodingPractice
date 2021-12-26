# include<stdio.h>
# include<stdlib.h>
int check(int*, int);
int static compare(const void*, const void*);
int N;

int main(){
    int cnt=0;
    int* arr;
    scanf("%d", &N);
    
    arr = (int*)malloc(sizeof(int)*(N+1));
    
    for(int i=1;i<N+1;i++)
        scanf("%d", &arr[i]);
        
    for(int i=1;i<N+1;i++)
        check(arr, i);
        
    for(int i=1;i<N+1;i++){
        if(arr[i]!=0)
            cnt++;
    }
    arr[0] = 0;
    printf("%d\n", cnt);
    
    qsort(arr, N+1, sizeof(int), compare);
    
    for(int i=1;i<N+1;i++)
        if(arr[i]!=0)
            printf("%d\n", arr[i]);
            
    return 0;
        
    
}

int check(int* arr, int num){
    int tmp;
    
    for(int i=1;i<N+1;i++){
        if(arr[i]==num){
            if(arr[num]!=0)
                return 0;
            else{
                arr[i]=0;
                check(arr, num);
            }
        }
    }
    
    if(arr[num]==0)
        return 0;
    
    //못 찾았을 경우 return 0, 찾을 경우 return 1
    
    tmp = arr[num];
    arr[num] = 0;
    check(arr, tmp);
    return 0;
}

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
