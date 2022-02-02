#include<stdio.h>
typedef struct{
    int x;
    int y;
}coor;

void merge(coor* cor, int N, int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    coor tmp[N];
    while(i<=mid && j<=high){
        if(cor[i].y > cor[j].y){
            tmp[k].y = cor[j].y;
            tmp[k++].x = cor[j++].x;
        }
        else if(cor[i].y < cor[j].y){
            tmp[k].y = cor[i].y;
            tmp[k++].x = cor[i++].x;
        }
        else{
            if(cor[i].x > cor[j].x){
                tmp[k].y = cor[j].y;
                tmp[k++].x = cor[j++].x;
            }
            else{
                tmp[k].y = cor[i].y;
                tmp[k++].x = cor[i++].x;
            }
        }
            
    }
    
    if(i<=mid){
        while(i<=mid){
            tmp[k].y = cor[i].y;
            tmp[k++].x = cor[i++].x;
        }
    }
    if(j<=high){
        while(j<=high){
            tmp[k].y = cor[j].y;
            tmp[k++].x = cor[j++].x;
        }
    }
    
    for(int l=low;l<=high;l++){
        cor[l].x = tmp[l].x;
        cor[l].y = tmp[l].y;
    }
    
}

void mergeSort(coor* cor, int N, int low, int high){
    if(low<high){
        int mid = (low + high) / 2;
        mergeSort(cor,N,low,mid);
        mergeSort(cor,N,mid+1,high);
        merge(cor,N,low,mid,high);
    }
}



int main(){
    int N;
    scanf("%d", &N);
    coor cor[N];
    for(int i=0;i<N;i++){
        scanf("%d %d", &cor[i].x, &cor[i].y);
    }
    mergeSort(cor,N,0,N-1);
    
    for(int i=0;i<N;i++)
        printf("%d %d\n", cor[i].x,cor[i].y);
        
    return 0;
    
}
