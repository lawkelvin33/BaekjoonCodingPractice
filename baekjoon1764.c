
#include<stdio.h>
#include<string.h>
int N;
char listN[500000][21];
char tmpN[500000][21];
void merge(int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(strcmp(listN[i],listN[j])>0){//j가 앞
            strcpy(tmpN[k++],listN[j++]);
        }
        else
            strcpy(tmpN[k++],listN[i++]);
    }
    if(i<=mid){
        while(i<=mid){
            strcpy(tmpN[k++],listN[i++]);
        }
    }
    if(j<=high){
        while(j<=high){
            strcpy(tmpN[k++],listN[j++]);
        }
    }
    for(int t=low;t<=high;t++){
        strcpy(listN[t],tmpN[t]);
    }
}
void mergeSort(int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}


int main(){
    int M;
    scanf("%d %d", &N, &M);
    int low,high;
    char tmp[21];
    int mid;
    int listR[500000]={0,}; //index of result list
    int total=0;
    
    for(int i=0;i<N;i++){
        scanf("%s", listN[i]);
    }
    mergeSort(0,N-1);

    for(int i=0;i<M;i++){
        low=0;
        high=N-1;
        scanf("%s", tmp);
        while(low<=high){
            mid = (low + high)/2;
            if(strcmp(listN[mid],tmp)>0) //tmp가 앞임
                high = mid-1;
            else if(strcmp(listN[mid],tmp)==0){
                listR[mid]=1;
                total++;
                break;
            }
            else
                low = mid + 1;
                
        }
    }
    printf("%d\n", total);
    for(int i=0;i<N;i++){
        if(listR[i]==1)
            puts(listN[i]);
    }
    return 0;
}




